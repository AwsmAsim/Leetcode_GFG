class DSU
{
public:
	DSU(vector<int> &vals) : parent(vals.size()), count(vals.size())
	{
		for (int i = 0; i < vals.size(); ++i)
		{
			parent[i] = i;
			count[i] = {vals[i], 1};
		}
	}

	int Find(int x)
	{
		if (x != parent[x])
			parent[x] = Find(parent[x]);
		return parent[x];
	}

	int Union(int x, int y, int maxval)
	{
		int xp = Find(x), yp = Find(y);
		if (xp == yp)
			return 0;
		int cx = count[xp].first == maxval ? count[xp].second : 0;
		int cy = count[yp].first == maxval ? count[yp].second : 0;
		parent[yp] = xp;
		count[xp] = {maxval, cx + cy};
		return cx * cy;
	}

private:
	vector<int> parent;
	vector<pair<int, int>> count; //{maxval,count of maxval}
};

class Solution
{
public:
	int numberOfGoodPaths(vector<int> &vals, vector<vector<int>> &edges)
	{
		int N = vals.size();
		for (auto &edge : edges)
			edge.push_back(max(vals[edge[0]], vals[edge[1]]));
		sort(edges.begin(), edges.end(), [](vector<int> &lhs, vector<int> &rhs)
			 { return lhs[2] < rhs[2]; });
		DSU dsu(vals);
		int res = N;
		for (auto &edge : edges)
			res += dsu.Union(edge[0], edge[1], edge[2]);
		return res;
	}
};