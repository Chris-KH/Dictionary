#include"Definition.h"
#include "Vietnamese.h"
#include <algorithm>


double editDistance(QString a, QString b) {
	int n = (int)a.length();
	int m = (int)b.length();
    QVector<QVector<int>> dp(n + 1, QVector<int>(m + 1, 0));
	for (int i = 0; i <= n; i++) dp[i][0] = i;
	for (int i = 0; i <= m; i++) dp[0][i] = i;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i - 1] == b[j - 1]) dp[i][j] = dp[i - 1][j - 1];
			else dp[i][j] = min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j])) + 1;
		}
	}
	return (double)dp[n][m];
}

void getWord(TrieNode* root, QString def, QVector<QPair<double, Word>>& defSearch) {
	if (root == nullptr) return;
    //if (defSearch.size() >= 6) return;

	if (root->wordEnd) {
		bool ok = false;
		double distance = 1e9;
		double temp;
        for (int i = 0; i < (int)root->word.definitions.size(); i++) {
            distance = min(distance, editDistance(def, root->word.definitions[i]));
            temp = distance / (double)max((double)def.length(), (double)root->word.definitions[i].length());
            if (temp <= 0.08) {
                if (defSearch.size() < 10) {
                    defSearch.push_back({ temp, root->word });
                } else {
                    auto maxIt = std::max_element(defSearch.begin(), defSearch.end(), [](const QPair<double, Word>& a, const QPair<double, Word>& b) {
                        return a.first < b.first;
                    });

                    if (temp < maxIt->first) {
                        *maxIt = { temp, root->word };
                    }
                }
                break;
            }
		}
		if (ok) defSearch.push_back({ temp, root->word });
    }

	for (int i = 0; i < sizeChar; i++) {
		getWord(root->childNode[i], def, defSearch);
	}
}

QVector<QPair<double, Word>> defSearch(Trie& trie, QString def) {
    QVector<QPair<double, Word>> v;
	getWord(trie.getRoot(), def, v);
    sort(v.begin(), v.end(), [](QPair<double, Word> a, QPair<double, Word> b) {return a.first < b.first; });
	return v;
}
