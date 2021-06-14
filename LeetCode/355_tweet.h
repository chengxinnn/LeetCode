#pragma once
#include <queue>
#include <vector>
#include <unordered_map>
using namespace std;
struct user {
	int uid;
	vector<int> tweets;
	vector<int>followed;
	user(int a) { uid = a; };
	user(int a, int b) { uid = a; tweets.push_back(b); };

};

class Twitter {
private:
	vector<user> users;
	unordered_map<int, int>um;
public:

	/** Initialize your data structure here. */
	Twitter() {

	}

	/** Compose a new tweet. */
	void postTweet(int userId, int tweetId) {
		if (!um.count(userId))
		{
			um[userId] = users.size();
			users.push_back(user(userId, tweetId));
		}
		else
		{
			users[um[userId]].tweets.push_back(tweetId);
		}

	}

	/** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
	vector<int> getNewsFeed(int userId) {
		user& one = users[um[userId]];
		priority_queue<int>pq;
		vector<int>ans;
		for (auto it = one.followed.begin(); it != one.followed.end(); it++)
		{
			user&star = users[um[*it]];
			for (const auto& tweet : star.tweets)
				pq.push(tweet);
			while (pq.size() > 10)
				pq.pop();
		}
		for (const auto& tweet : one.tweets)
			pq.push(tweet);
		while (pq.size() > 10)
			pq.pop();
		while (pq.size())
		{
			ans.push_back(pq.top());
			pq.pop();
		}
		return ans;

	}

	/** Follower follows a followee. If the operation is invalid, it should be a no-op. */
	void follow(int followerId, int followeeId) {
		if (!um.count(followerId))
		{
			um[followerId] = users.size();
			users.push_back(user(followerId));
		}
		if (!um.count(followeeId))
		{
			um[followeeId] = users.size();
			users.push_back(user(followeeId));
		}
		users[um[followerId]].followed.push_back(followeeId);

	}

	/** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
	void unfollow(int followerId, int followeeId) {
		if (!um.count(followerId) || !um.count(followeeId)) return;
		user& one = users[um[followerId]];
		for (auto it = one.followed.begin(); it != one.followed.end() || !one.followed.empty();)
			if (*it == followeeId)
				it = one.followed.erase(it);
			else
				++it;
		    
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