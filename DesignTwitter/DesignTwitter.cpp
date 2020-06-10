
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <queue>
#include <algorithm>
#include <iterator>

using namespace std;

/*
https://leetcode.com/problems/design-twitter/

Design a simplified version of Twitter where users can post tweets, follow/unfollow another user and is able to see the 10 most recent tweets in the user's news feed. Your design should support the following methods:

postTweet(userId, tweetId): Compose a new tweet.
getNewsFeed(userId): Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent.
follow(followerId, followeeId): Follower follows a followee.
unfollow(followerId, followeeId): Follower unfollows a followee.
Example:

Twitter twitter = new Twitter();

// User 1 posts a new tweet (id = 5).
twitter.postTweet(1, 5);

// User 1's news feed should return a list with 1 tweet id -> [5].
twitter.getNewsFeed(1);

// User 1 follows user 2.
twitter.follow(1, 2);

// User 2 posts a new tweet (id = 6).
twitter.postTweet(2, 6);

// User 1's news feed should return a list with 2 tweet ids -> [6, 5].
// Tweet id 6 should precede tweet id 5 because it is posted after tweet id 5.
twitter.getNewsFeed(1);

// User 1 unfollows user 2.
twitter.unfollow(1, 2);

// User 1's news feed should return a list with 1 tweet id -> [5],
// since user 1 is no longer following user 2.
twitter.getNewsFeed(1);
*/

//class Twitter {
//	unordered_map<int, unordered_set<int>> followers;
//	unordered_map<int, deque<int>> tweets; // IDs, not timestamps! !!!!!
//public:
//	/** Initialize your data structure here. */
//	Twitter() {
//
//	}
//
//	/** Compose a new tweet. */
//	void postTweet(int userId, int tweetId) {
//		tweets[userId].push_back(tweetId);
//	}
//
//	struct Comparator {
//		Comparator() {
//
//		}
//
//		bool operator() (const pair<deque<int>::const_reverse_iterator, deque<int>::const_reverse_iterator>& left, const pair<deque<int>::const_reverse_iterator, deque<int>::const_reverse_iterator>& right) const {
//			return *left.first < *right.first;
//		}
//	};
//
//	class Feed {
//		// list?
//		priority_queue<pair<deque<int>::const_reverse_iterator, deque<int>::const_reverse_iterator>, vector<pair<deque<int>::const_reverse_iterator, deque<int>::const_reverse_iterator>>, Comparator> feed;
//
//	public:
//		explicit Feed(const unordered_map<int, deque<int>>& tweets) : feed(Comparator()) {
//
//		}
//
//		void addUser(const deque<int>& userTweets) {
//			if (!userTweets.empty())
//				feed.emplace(rbegin(userTweets), rend(userTweets));
//		}
//
//		vector<int> toVector(int n) {
//			vector<int> result;
//			result.reserve(n);
//
//			for (int i = 0; i < n; ++i) {
//				if (feed.empty())
//					break;
//				auto p = feed.top();
//				feed.pop();
//				result.push_back(*p.first++);
//				if (p.first != p.second)
//					feed.emplace(p.first, p.second);
//			}
//
//			// ... copy_n?
//
//			return result;
//		}
//	};
//
//	/** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
//	vector<int> getNewsFeed(int userId) {
//		Feed feed(tweets);
//		
//		// userId + followers[userId]
//		feed.addUser(tweets[userId]);
//		for (auto followerId: followers[userId])
//			feed.addUser(tweets[followerId]);
//
//		return feed.toVector(10);
//	}
//
//	/** Follower follows a followee. If the operation is invalid, it should be a no-op. */
//	void follow(int followerId, int followeeId) {
//		if (followerId != followeeId)
//			followers[followerId].insert(followeeId);
//	}
//
//	/** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
//	void unfollow(int followerId, int followeeId) {
//		followers[followerId].erase(followeeId);
//	}
//};

//Runtime: 68 ms, faster than 81.33% of C++ online submissions for Design Twitter.
//Memory Usage : 21 MB, less than 100.00% of C++ online submissions for Design Twitter.
class Twitter {

	typedef int UserId;
	typedef int TweetId;
	typedef int TweetData;

	static constexpr size_t NumberOfTweetsInFeed = 10;

	struct Tweet {
		TweetId id;
		TweetData data;

		Tweet(TweetId id, TweetData data) : id(id), data(data) {}

		bool operator< (const Tweet& other) const {
			return id < other.id;
		}
	};

	typedef list<Tweet> TweetsContainer;
	typedef list<Tweet>::const_reverse_iterator TweetIterator;
	typedef pair<TweetIterator, TweetIterator> TweetRange;

	struct User {

		UserId id;
		unordered_set<UserId> followees;
		TweetsContainer tweets;

		void postTweet(TweetId id, TweetData data) {
			tweets.emplace_back(id, data);
		}

		void follow(UserId followeeId) {
			followees.insert(followeeId);
		}

		void unfollow(UserId followeeId) {
			followees.erase(followeeId);
		}
	};

	typedef unordered_map<UserId, User> UsersContainer;

	UsersContainer users;
	TweetId nextTweetId;

	TweetId newTweetId() {
		return nextTweetId++;
	}

public:
	/** Initialize your data structure here. */
	Twitter() : nextTweetId(1) {

	}

	/** Compose a new tweet. */
	void postTweet(int userId, int tweetId) {
		users[userId].postTweet(newTweetId(), tweetId);
	}

	struct Comparator {
		Comparator() {

		}

		bool operator() (const TweetRange& left, const TweetRange& right) const {
			return *left.first < *right.first;
		}
	};

	class Feed {
		priority_queue<TweetRange, vector<TweetRange>, Comparator> feed;

	public:
		explicit Feed(const UsersContainer& users) : feed(Comparator()) {

		}

		void addUser(const User& user) {
			if (!user.tweets.empty())
				feed.emplace(rbegin(user.tweets), rend(user.tweets));
		}

		vector<int> toVector(int n) {
			vector<int> result;
			result.reserve(n);

			for (int i = 0; i < n; ++i) {
				if (feed.empty())
					break;
				auto p = feed.top();
				feed.pop();
				result.push_back((*p.first++).data);
				if (p.first != p.second)
					feed.emplace(p.first, p.second);
			}

			// ... copy_n?

			return result;
		}
	};

	/** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
	vector<int> getNewsFeed(int userId) {
		Feed feed(users);

		// userId + followers[userId]
		feed.addUser(users[userId]);
		for (auto followeeId : users[userId].followees)
			feed.addUser(users[followeeId]);

		return feed.toVector(NumberOfTweetsInFeed);
	}

	/** Follower follows a followee. If the operation is invalid, it should be a no-op. */
	void follow(int followerId, int followeeId) {
		if (followerId != followeeId)
			users[followerId].follow(followeeId);
	}

	/** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
	void unfollow(int followerId, int followeeId) {
		if (followerId != followeeId)
			users[followerId].unfollow(followeeId);
	}
};

/**
* Your Twitter object will be instantiated and called as such:
* Twitter* obj = new Twitter();
* obj->postTweet(userId,tweetId);
* vector<int> param_2 = obj->getNewsFeed(userId);
* obj->follow(followerId,followeeId);
* obj->unfollow(followerId,followeeId);
*/

void printFeed(const vector<int>& feed) {
	copy(begin(feed), end(feed), ostream_iterator<int>(cout, " "));
	cout << endl;
}

void printLine() {
	cout << "----------------------------------------" << endl;
}

int main()
{
	{
		Twitter twitter;

		// User 1 posts a new tweet (id = 5).
		twitter.postTweet(1, 5);

		// User 1's news feed should return a list with 1 tweet id -> [5].
		printFeed(twitter.getNewsFeed(1));

		// User 1 follows user 2.
		twitter.follow(1, 2);

		// User 2 posts a new tweet (id = 6).
		twitter.postTweet(2, 6);

		// User 1's news feed should return a list with 2 tweet ids -> [6, 5].
		// Tweet id 6 should precede tweet id 5 because it is posted after tweet id 5.
		printFeed(twitter.getNewsFeed(1));

		// User 1 unfollows user 2.
		twitter.unfollow(1, 2);

		// User 1's news feed should return a list with 1 tweet id -> [5],
		// since user 1 is no longer following user 2.
		printFeed(twitter.getNewsFeed(1));

		printLine();
	}
	{
		/*
		["Twitter","postTweet","postTweet","getNewsFeed"]
		[[],[1,5],[1,3],[1]]

		*/

		Twitter twitter;
		twitter.postTweet(1, 5);
		twitter.postTweet(1, 3);
		printFeed(twitter.getNewsFeed(1)); // 3 5
		printLine();
	}
	{
		/*
		["Twitter","postTweet","follow","getNewsFeed"]
		[[],[1,5],[1,1],[1]]

		*/

		Twitter twitter;
		twitter.postTweet(1, 5);
		twitter.follow(1, 1);
		printFeed(twitter.getNewsFeed(1)); // 5
		printLine();
	}
	{
		/*
		["Twitter","postTweet","postTweet","postTweet","postTweet","postTweet","postTweet","postTweet","postTweet","postTweet","postTweet","getNewsFeed","follow","getNewsFeed"]
		[[],[2,5],[1,3],[1,101],[2,13],[2,10],[1,2],[2,94],[2,505],[1,333],[1,22],[2],[2,1],[2]]

		[2,5],[1,3],[1,101],[2,13],[2,10],[1,2],[2,94],[2,505],[1,333],[1,22]

		[2],
		[2,1],
		[2]
		*/

		Twitter twitter;
		twitter.postTweet(2, 5);
		twitter.postTweet(1, 3);
		twitter.postTweet(1, 101);
		twitter.postTweet(2, 13);
		twitter.postTweet(2, 10);
		twitter.postTweet(1, 2);
		twitter.postTweet(2, 94);
		twitter.postTweet(2, 505);
		twitter.postTweet(1, 333);
		twitter.postTweet(1, 22);
		printFeed(twitter.getNewsFeed(2)); // [505, 94, 10, 13, 5]
		twitter.follow(2, 1);
		printFeed(twitter.getNewsFeed(2)); // [22, 333, 505, 94, 2, 10, 13, 101, 3, 5]

		// [null, null, null, null, null, null, null, null, null, null, null, [505, 94, 10, 13, 5], null, [22, 333, 505, 94, 2, 10, 13, 101, 3, 5]]
		printLine();
	}
    return 0;
}

