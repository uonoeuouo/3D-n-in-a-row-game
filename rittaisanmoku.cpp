#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using vl = vector<ll>;
using vd = vector<double>;
using vs = vector<string>;
using vc = vector<char>;
using vb = vector<bool>;
using vvl = vector<vl>;
using vvs = vector<vs>;
using vvc = vector<vc>;
using pl = pair<ll, ll>;
#define all(x) (x).begin(), (x).end()
const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
const int dy[8] = {0, 1, 0, -1, 1, -1, 1, -1};
const ll inf = 1000000000000000000;
const ll mod = 998244353;

int multipf(vector<ll> &n)
{
    if (n.size() == 0)
        return 0;
    for (int i = 0; i < n.size(); i++)
    {
        cout << n[i] << " ";
    }
    cout << endl;
    return 0;
}

int multipf(vector<string> &s)
{
    if (s.size() == 0)
        return 0;
    for (int i = 0; i < s.size(); i++)
    {
        cout << s[i] << " ";
    }
    cout << endl;
    return 0;
}

double EuclidDis(pair<double, double> a, pair<double, double> b)
{
    return sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}

// 配列の個数を確認しろ

int main()
{

    cout << "立体n目並べゲームを開始します" << endl;
    cout << "nを入力してください．自分のコマをn個並べると勝ちです．" << endl;
    int n;
    cin >> n;
    vector<vector<vector<ll> > > a(n, vector<vector<ll> > (n, vector<ll> (n, -inf))); // 空-1、o0、x1
    bool turn = 0;         // o0,x1
    while (1)
    {
        // 入力
        int x, y, z;
        cout << "現在" << turn << "のターンです．" << endl;
        cout << "コマを置く座標を入力してください．" << endl;
        cout << "x座標,y座標,z座標の順に空白区切りで入力します．" << endl;
        cin >> x >> y >> z;
        if (a[x][y][z] == -inf)
        {
            a[x][y][z] = turn;
            turn = !turn;
        }else{
            cout << "置くことができません．" << endl;
        }

        // 出力
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                for (int k = 0; k < n; k++)
                {
                    if (a[i][j][k] == 0){
                        cout << "o";
                    }else if (a[i][j][k] == 1){
                        cout << "x";
                    }else{
                        cout << ".";
                    }
                }

                cout << endl;
                
            }
            cout << endl;
        }


        // 判定
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                for (int k = 0; k < n; k++)
                {
                    //z軸0
                    for (int l = 0; l < 8; l++)
                    {
                        int cnt = 0;
                        for (int m = 0; m < 3; m++)
                        {
                            if(0 <= i + dx[l]*m && i + dx[l]*m <= n-1 && 0 <= j + dy[l]*m && j + dy[l]*m <= n-1 && 0 <= k + 0 && k + 0 <= n-1){
                                if(a[i][j][k] == a[i + dx[l]*m][j + dy[l]*m][k + 0] && a[i][j][k] != -inf)cnt++;
                            }
                        }
                        if(cnt == 3){
                            cout << !turn << "win" << endl;
                            return 0;
                        }
                    }

                    //z軸+1
                    for (int l = 0; l < 8; l++)
                    {
                        int cnt = 0;
                        for (int m = 0; m < 3; m++)
                        {
                            if(0 <= i + dx[l]*m && i + dx[l]*m <= n-1 && 0 <= j + dy[l]*m && j + dy[l]*m <= n-1 && 0 <= k + 1 && k + 1 <= n-1){
                                if(a[i][j][k] == a[i + dx[l]*m][j + dy[l]*m][k + 1*m] && a[i][j][k] != -inf){
                                    cnt++;
                                    //cout << i << " " << j << " " << k << " " << l << " " << m << endl;
                                }
                            }
                        }

                        if(cnt == 3){
                            cout << !turn << "win" << endl;
                            return 0;
                        }
                    }

                    //z軸-1
                    for (int l = 0; l < 8; l++)
                    {
                        int cnt = 0;
                        for (int m = 0; m < 3; m++)
                        {
                            if(0 <= i + dx[l]*m && i + dx[l]*m <= n-1 && 0 <= j + dy[l]*m && j + dy[l]*m <= n-1 && 0 <= k - 1 && k - 1 <= n-1){
                                if(a[i][j][k] == a[i + dx[l]*m][j + dy[l]*m][k - 1*m] && a[i][j][k] != -inf)cnt++;
                            }
                        }
                        if(cnt == 3){
                            cout << !turn << "win" << endl;
                            return 0;
                        }
                    }
                    
                    //上
                    int cnt1 = 0;
                    for (int l = 0; l < 3; l++)
                    {
                        if(k+1 <= n-1){
                            if(a[i][j][k] == a[i][j][k + l] && a[i][j][k] != -inf)cnt1++;
                        }
                    }
                    if(cnt1 == 3){
                        cout << !turn << "win" << endl;
                        return 0;
                    }

                    //下
                    int cnt2 = 0;
                    for (int l = 0; l < 3; l++)
                    {
                        if(0 <= k-1){
                            if(a[i][j][k] == a[i][j][k - l] && a[i][j][k] != -inf)cnt2++;
                        }
                    }
                    if(cnt2 == 3){
                        cout << !turn << "win" << endl;
                        return 0;
                    }
                    
                }

            }
        }

        
        //引き分け
        int allcnt = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                for (int k = 0; k < n; k++)
                {
                    if(a[i][j][k] != -inf)allcnt++;
                }
                
            }
            
        }
        if(allcnt == n*n*n){
            cout << "draw" << endl;
            return 0;
        }
        

    }

    return 0;
}
