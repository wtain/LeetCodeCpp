
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cassert>
/*
class SquareMatrix
{
	std::vector<char> m_data;
	size_t m_n;

public:
	explicit SquareMatrix(size_t n)
		: m_data(n * n)
		, m_n(n)
	{

	}

	char operator() (size_t i, size_t j) const
	{
		assert(i < m_n && j < m_n);
		return m_data[i*m_n + j];
	}

	char &operator() (size_t i, size_t j)
	{
		assert(i < m_n && j < m_n);
		return m_data[i*m_n + j];
	}

	size_t Dimension() const
	{
		return m_n;
	}
};

class DeterministicStateMachine
{
	SquareMatrix m_transitions;
	size_t m_state;
public:
	explicit DeterministicStateMachine(size_t n)
		: m_transitions(n + 1)
		, m_state(0)
	{

	}

	size_t State() const
	{
		return m_state;
	}

	void Move(char c)
	{
		m_state = (*this) (m_state)
	}

	void AddWord(const std::string& str)
	{
		assert(str.length() <= m_transitions.Dimension());
		for (size_t i = 0; i < str.length(); ++i)
		{
			m_transitions(i, i + 1) = str[i];
		}
	}
};
*/

/*

class DeterministicStateMachine
{
public:
	typedef size_t State;
	typedef char Label;
	typedef std::map<std::pair<State, Label>, State> TransitionsMap;

private:

	TransitionsMap m_transitions;

public:

	DeterministicStateMachine()
	{

	}

	virtual void AddTransition(State state, Label transition, State targetState)
	{
		m_transitions.insert(std::make_pair(std::make_pair(state, transition), targetState));
	}

	bool HasTransition(State state, Label transition) const
	{
		return m_transitions.end() != m_transitions.find(std::make_pair(state, transition));
	}

	State Move(State state, Label transition) const
	{
		assert(HasTransition(state, transition));
		return m_transitions.find(std::make_pair(state, transition))->second;
	}
};

class DSMWalker : public DeterministicStateMachine
{
public:
	DSMWalker()
	{

	}

	void AddWord(const std::string& str)
	{
		for (State state = 0; state < str.length(); ++state)
			AddTransition(state, str[state], state + 1);
	}
};

class SuffixRefAwareDSMWalker : public DSMWalker
{
	std::map<State, State> m_suffixRefs;
	std::map<State, State> m_parents;

public:

	SuffixRefAwareDSMWalker()
	{

	}

	void AddTransition(State state, Label transition, State targetState) override
	{
		DSMWalker::AddTransition(state, transition, targetState);
		std::pair<State, State> p = std::make_pair(targetState, state);
		m_parents.insert(p);
	}

	State SuffixRef(State state)
	{
		auto it = m_suffixRefs.find(state);
		if (it != m_suffixRefs.end())
			return it->second;
		State u = m_parents[state];
	}
};

size_t FindStringAK(const std::string& str, const std::string tok)
{
	SuffixRefAwareDSMWalker sm;
	sm.AddWord(tok);
	SuffixRefAwareDSMWalker::State state = 0;

	for (size_t i = 0; i < str.length(); ++i)
	{
		if (state == tok.length())
			return i + 1 - state;
		if (str[i] == tok[state])
		{
			++state;
			continue;
		}

	}
	return std::string::npos;
}			   */

class Trie
{
	struct Vertex
	{
		std::map<char, size_t> transitions;
		bool leaf;

		size_t p;
		char pch;

		size_t depth;

		size_t link;

		std::map<char, size_t> go;

		Vertex() : leaf(false), p(std::string::npos), pch(0), link(0), depth(0) {}

		Vertex(size_t p, char pch, size_t depth) : leaf(false), p(p), pch(pch), link(std::string::npos), depth(depth) {}
	};

	std::vector<Vertex> m_vertices;

public:

	Trie()
	{
		m_vertices.push_back(Vertex());
	}

	void AddWord(const std::string& str)
	{
		size_t state = 0;
		for (size_t i = 0; i < str.length(); ++i)
		{
			auto it = m_vertices[state].transitions.find(str[i]);
			if (it == m_vertices[state].transitions.end())
			{
				size_t newV = m_vertices.size();
				m_vertices[state].transitions.insert(it, std::make_pair(str[i], newV));
				m_vertices.push_back(Vertex(state, str[i], i));
				state = newV;
			}
			else
				state = it->second;
		}
		m_vertices[state].leaf = true;
	}

	size_t GetLink(size_t v)
	{
		if (m_vertices[v].link == std::string::npos)
		{
			if (0 == v || m_vertices[v].p == 0)
				m_vertices[v].link = 0;
			else
				m_vertices[v].link = Go(GetLink(m_vertices[v].p), m_vertices[v].pch);
		}
			
		return m_vertices[v].link;
	}

	size_t Go(size_t v, char c)
	{
		auto it = m_vertices[v].go.find(c);
		if (m_vertices[v].go.end() == it)
		{
			auto it2 = m_vertices[v].transitions.find(c);
			size_t targetState = std::string::npos;
			if (it2 != m_vertices[v].transitions.end())
				targetState = it2->second;
			else
				targetState = v == 0 ? 0 : Go(GetLink(v), c);

			it = m_vertices[v].go.insert(it, std::make_pair(c, targetState));
		}
		return it->second;
	}

	bool IsEndState(size_t state)
	{
		return m_vertices[state].leaf;
	}

	size_t Depth(size_t state)
	{
		return m_vertices[state].depth;
	}
};

size_t FindStringAK(const std::string& str, const std::string tok)
{
	Trie trie;
	trie.AddWord(tok);

	size_t state = 0;
	for (size_t i = 0; i < str.length(); ++i)
	{
		state = trie.Go(state, str[i]);
		if (trie.IsEndState(state))
			return i + 1 - tok.length();
	}
	return std::string::npos;
}

void FindStringAK_All(const std::string& str, const std::string tok, std::vector<size_t>& r)
{
	r.clear();
	Trie trie;
	trie.AddWord(tok);

	size_t state = 0;
	for (size_t i = 0; i < str.length(); ++i)
	{
		state = trie.Go(state, str[i]);
		if (trie.IsEndState(state))
			r.push_back(i + 1 - tok.length());
	}
}

void FindAllStringsAK_All(const std::string& str, const std::vector<std::string> toks, std::vector<size_t>& r)
{
	r.clear();
	Trie trie;
	for (const auto& tok: toks)
		trie.AddWord(tok);

	size_t state = 0;
	for (size_t i = 0; i < str.length(); ++i)
	{
		state = trie.Go(state, str[i]);
		if (trie.IsEndState(state))
			r.push_back(i - trie.Depth(state));
	}
}

std::vector<size_t> CalcPrefix(const std::string& str)
{
	std::vector<size_t> p(str.length());
	p[0] = 0;
	for (size_t i = 1; i < str.length(); ++i)
	{
		size_t k = p[i-1];
		while (1)
		{
			if (str[i] == str[k])
			{
				p[i] = k + 1;
				break;
			}
			else if (0 == k)
			{
				p[i] = 0;
				break;
			}
			else
				k = p[k-1];
		}
	}

	return p;
}

size_t FindSubstringKMP(const std::string& str, const std::string& token)
{
	const auto prefix = CalcPrefix(token);
	for (size_t i = 0, j = 0; i != str.length(); ++i)
	{
		if (str[i] == token[j])
		{
			++j;
			if (j == token.length())
				return i+1 - token.length();
		}
		else
		{
			while (j && str[i] != token[j])
				j = prefix[j-1];
			if (str[i] == token[j])
				++j;
		}
	}
	return std::string::npos;
}

std::vector<size_t> FindSubstringAllKMP(const std::string& str, const std::string& token)
{
	std::vector<size_t> rv;
	const auto prefix = CalcPrefix(token);
	for (size_t i = 0, j = 0; i != str.length(); ++i)
	{
		if (str[i] == token[j])
		{
			++j;
			if (j == token.length())
			{
				rv.push_back(i + 1 - token.length());
				j = 0;
			}
		}
		else
		{
			while (j && str[i] != token[j])
				j = prefix[j-1];
			if (str[i] == token[j])
				++j;
		}
	}
	return rv;
}

void AhoKorasik()
{
	//                 0         1
	//                 0123456789012345
	std::string str = "abcabcdabcdabcde";
	// 3 7 11  6 10  13

	std::string str2 = "abcabcabd";

	/*Trie trie;
	trie.AddWord("abc");
	trie.AddWord("abcd");
	trie.AddWord("aba");
	trie.AddWord("ad");*/

	std::cout << FindStringAK(str, "abcd") << std::endl;
	std::cout << FindStringAK(str, "abxx") << std::endl;
	std::cout << FindStringAK(str, "bcdab") << std::endl;
	std::cout << FindStringAK(str2, "abcabd") << std::endl;

	std::cout << FindSubstringKMP(str, "abcd") << std::endl;
	std::cout << FindSubstringKMP(str, "abxx") << std::endl;
	std::cout << FindSubstringKMP(str, "bcdab") << std::endl;
	std::cout << FindSubstringKMP(str2, "abcabd") << std::endl;

	std::vector<size_t> v;
	FindStringAK_All(str, "abc", v);
	for (auto i : v)
		std::cout << i << " ";
	std::cout << std::endl;

	v = FindSubstringAllKMP(str, "abc");
	for (auto i : v)
		std::cout << i << " ";
	std::cout << std::endl;

	FindAllStringsAK_All(str, { "abcd", "dabc", "cde" }, v);
	for (auto i : v)
		std::cout << i << " ";
	std::cout << std::endl;
}

using namespace std;

class Solution {
public:
	int strStr(string haystack, string needle) {
		if (haystack.empty())
		{
			if (!needle.empty())
				return -1;
			return 0;
		}
		if (needle.empty())
			return 0;
		vector<int> p(needle.length());
		p[0] = 0;
		for (int i = 1; i < needle.length(); ++i)
		{
			int k = p[i - 1];
			while (1)
			{
				if (needle[i] == needle[k])
				{
					p[i] = k + 1;
					break;
				}
				else if (k == 0)
				{
					p[i] = 0;
					break;
				}
				else
				{
					k = p[k - 1];
				}
			}
		}

		int k = 0;
		for (int i = 0; i < haystack.length(); ++i)
		{
			if (haystack[i] == needle[k])
			{
				k++;
				if (k == needle.length())
					return i - k + 1;
			}
			else
			{
				while (k > 0 && haystack[i] != needle[k])
					k = p[k - 1];
				if (haystack[i] == needle[k])
					k++;
			}
		}
		return -1;
	}
};

int main()
{
	//AhoKorasik();

	/*auto p1 = CalcPrefix("abcdabscabcdabia");
	for (auto i : p1)
		std::cout << i << " ";
	std::cout << std::endl;

	auto p2 = CalcPrefix("abcdabcabcdabcdab");
	for (auto i : p2)
		std::cout << i << " ";
	std::cout << std::endl;*/

	auto p2 = CalcPrefix("aabaaac");
	cout << Solution().strStr("aabaaabaaac", "aabaaac") << endl;

    return 0;
}

