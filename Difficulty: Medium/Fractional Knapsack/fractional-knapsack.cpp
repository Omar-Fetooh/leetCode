class Solution {
	public:
	
  struct Item
  {
	  int val;
	  int weight;
	  double rate;
  }; 

  static bool Comp(Item A, Item B) {
	  return B.rate < A.rate;
  };

	double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
		// code here
		vector<Item> v;
		for (int i = 0; i < val.size(); i++) {
			v.push_back({ val[i], wt[i], val[i] / double(wt[i]) });
		}
		sort(v.begin(), v.end(), Comp);
		double sum;
		for (int i = 0; i < v.size(); i++) {
			if (capacity >= v[i].weight) {
				sum += v[i].val;
				capacity -= v[i].weight;
			}
			else {
				sum += ((double(capacity) / v[i].weight) * v[i].val);
				break;
			}
		}
		return sum;
	}
};
