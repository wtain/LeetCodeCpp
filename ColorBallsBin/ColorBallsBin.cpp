
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <memory>
#include <iomanip>

using namespace std;

class Random
{
public:
	Random()
	{
		srand(static_cast<unsigned>(time(nullptr)));
	}

	int Next()
	{
		return rand();
	}

	int Next(int a, int b)
	{
		return a + Next() % (b - a + 1);
	}
};

class ColorBallsBin
{
	shared_ptr<Random> m_random;
	vector<int> m_counts;

	struct SegmentTreeNode
	{
		int count;
		int color;

		SegmentTreeNode()
			: SegmentTreeNode(0)
		{

		}

		explicit SegmentTreeNode(int cnt)
			: SegmentTreeNode(cnt, -1)
		{					  

		}

		SegmentTreeNode(int cnt, int clr)
			: count(cnt)
			, color(clr)
		{

		}
	};

	vector<SegmentTreeNode> m_nodes;

public:

	// 0 1 2
	// 0 1 2 3 4 5
	//
	ColorBallsBin(const shared_ptr<Random>& random, const vector<int>& counts)
		: m_random(random)
		, m_counts(counts)
	{
		const int n = counts.size();
		m_nodes.resize(2 * n);
		
		buildTree(counts, 0, 0, n - 1);
		/*
		for (int i = n; i < 2 * n; ++i)
		{
			int j = i - n;
			m_nodes[i] = SegmentTreeNode(counts[j], j);
		}
		
		for (int i = n - 1; i >= 0; --i)
		{
			int i1 = 2 * i + 1;
			int i2 = 2 * i + 2;
			m_nodes[i] = SegmentTreeNode(m_nodes[i1].count + m_nodes[i2].count);
		}*/
	}

	void buildTree(const vector<int>& counts, int index, int lo, int hi)
	{
		if (lo == hi)
		{
			m_nodes[index] = SegmentTreeNode(counts[lo], lo);
			return;
		}

		int mid = lo + (hi - lo) / 2;

		int left = 2 * index + 1;
		int right = 2 * index + 2;

		buildTree(counts, left, lo, mid);
		buildTree(counts, right, mid + 1, hi);

		m_nodes[index] = SegmentTreeNode(m_nodes[left].count + m_nodes[right].count);
	}

	int Total() const
	{
		return m_nodes[0].count;
	}

	int Take()
	{
		int value = m_random->Next(0, Total() - 1);
		int index = 0;
		while (m_nodes[index].color == -1)
		{
			--m_nodes[index].count;
			int left = 2 * index + 1;
			int right = 2 * index + 2;
			if (value >= m_nodes[left].count)
			{
				index = right;
				value -= m_nodes[left].count;
			}
			else
				index = left;
		}
		return m_nodes[index].color;
	}

	const vector<int>& Counts() const
	{
		return m_counts;
	}
};

class ColorBallsBinTester
{
	shared_ptr<Random> m_random;
	ColorBallsBin m_bin;

public:
	explicit ColorBallsBinTester(const vector<int>& colors)
		: m_random(make_shared<Random>())
		, m_bin(m_random, colors)
	{

	}

	void Test(int nIterations, int color)
	{
		int cnt = 0;
		double probExpected = static_cast<double>(m_bin.Counts()[color]) / static_cast<double>(m_bin.Total());
		for (int i = 0; i < nIterations; ++i)
		{
			ColorBallsBin bin = m_bin;
			int c = bin.Take();
			if (c == color)
				++cnt;
		}
		double prob = static_cast<double>(cnt) / static_cast<double>(nIterations);
		cout << "Statictical probability: " << setprecision(2) << prob << "%, expected: " << probExpected << endl;
	}
};

int main()
{
	vector<int> colors = { 10, 20, 30, 40, 50 };
	ColorBallsBinTester tester(colors);
	tester.Test(10000, 0); // 0.1 1/15
	tester.Test(10000, 1); // 0.2 2/15
	tester.Test(10000, 2); // 0.3 3/15=1/5=0.2
	tester.Test(10000, 3); // 0.4 4/15
	tester.Test(10000, 4); // 	  5/15=1/3=0.33

    return 0;
}

