class Solution {
public:
	int movingCount(int m, int n, int k) {

		bool*visited = new bool[m * n]();
		for_each(visited, visited + m * m, [](bool & x) {cout << x << " "; });
		int ans = back(0, m, 0, n, k, visited);
		return ans;
	}
	int back(int r, const int &rs, int c, const int& cs, const int&k, bool*vis)
	{
		int count = 0;
		if (getin(r, rs, c, cs, k, vis))
		{
			vis[r * cs + c] = 1;
			count = 1 + back(r + 1, rs, c + 1, cs, k, vis) + back(r + 1, rs, c - 1, cs, k, vis)
				+ back(r - 1, rs, c + 1, cs, k, vis) + back(r - 1, rs, c - 1, cs, k, vis);
		}
		return count;
	}
	bool getin(int r, const int &rs, int c, const int& cs, const int&k, bool*vis)
	{
		if (r < 0 || c < 0 || r >= rs || c >= cs) return  0;
		int ans = 0;
		ans += r % 10 + r / 10;
		ans += c % 10 + c / 10;
		return ans <= k && !vis[r * cs + c];
	}

};