#include <map>
#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int cases = 1;
	int t;
	while (cin >> t, t) {
		cout << "Scenario #" << cases++ << "\n";

		map<int, int> team;
		for (int i = 1; i <= t; i++) {
			int qtd; cin >> qtd;
			while(qtd--) {
				int val; cin >> val;
				team[val] = i;
			}
		}

		queue<int> q_team;
		queue<int> q[t+1];
		map<int, bool> used;

		string op;
		while (cin >> op, op != "STOP") {

			if (op == "ENQUEUE") {
				int val; cin >> val;
				int act = team[val];

				q[act].push(val);
				if (used[act]) continue;
				used[act] = true;
				q_team.push(act);
			} else {
				int team_top = q_team.front();
				int val_top = q[team_top].front();

				cout << val_top << "\n";

				q[team_top].pop();
				if (q[team_top].size() == 0) {
					q_team.pop();
					used[team_top] = false;
				}
			}
		}
		cout << "\n";
	}
}