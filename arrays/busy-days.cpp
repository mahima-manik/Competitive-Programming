/*
The marketing team at Booking.com wants to identify our partners’ busiest days – the dates with the maximum number of reservations per property. Once they know which dates are most popular with guests, the marketing team can use this information to acquire more rooms on these high demand dates. Can you help?

There’s one property per test case, each with a list of reservation check-in and check-out dates (all stays are inclusive). We need you to find the date with the most reservations at each property.

Input Format

The first line of each test file contains the number of test cases . 
For each test case, the first line contains the number of reservations . 
 lines follow, each contain two space separated dates ,  in the -- format.

Constraints

--  --
Output Format

For each test case, print the date with most reservations in the -- format in a new line. If multiple dates have the same number of reservations, return the earliest one.

Sample Input 0

1
3
2018-01-01 2018-01-03
2018-01-02 2018-01-05
2018-01-03 2018-01-06
Sample Output 0

2018-01-03
Explanation 0

It is clear from the input that among the 3 reservations made, 2018-01-03 had the maximum number of reservations.
*/
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

int monthDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int countLeapYears (int y, int m)   {
    if (m>2)
        return (y/4 - y/100 + y/400);
    else
        return ((y-1)/4 - (y-1)/100 + (y-1)/400);
}

int getyear(string d)   {
    //cout << "here " <<  d.substr(0, 4)  << " " << stoi(d.substr(0, 4)) << "\n";
    return stoi(d.substr(0, 4));
}

int getmonth(string d)   {
    return stoi(d.substr(5, 2));
}

int getdate(string d)   {
    return stoi(d.substr(8, 2));
}

long int getnumdays (string dt1)  {
    long int n1 = getyear(dt1)*365 + getdate(dt1);
    for (int i=0; i<getmonth(dt1)-1; i++) {
        n1 += monthDays[i];
    }
    n1 += countLeapYears(getmonth(dt1), getyear(dt1));
    return n1;
}
// Complete the solve function below.
string solve(vector<vector<string>> reservations) {
    string dt1 = "2018-01-01";
    string dt2 = "2020-12-31";
    int n2 = getnumdays(dt2);
    int n1 = getnumdays(dt1);
    //cout << n2-n1 << endl;
    vector<int> arr(n2-n1+2, 0);
    vector<string> strarr(n2-n1+2, "");
    int t1, t2;
    int n = reservations.size();
    for (int i=0; i<n; i++) {
        //cout << reservations[i][0] << " " << reservations[i][1] << "\n";
        t1 = getnumdays(reservations[i][0]) - n1;
        t2 = getnumdays(reservations[i][1]) - n1 + 1;
        arr[t1] += 1;
        strarr[t1] = reservations[i][0];
        //arr[t2-1] += 1;
        arr[t2] -= 1;
        //cout << t1 << " " << arr[t1] << " " << t2 << " " << arr[t2] << "\n";
        strarr[t2] = reservations[i][1];
        //cout << t1 << " "<< t2 << "\n";
    }
    int ans = -1;
    int bs;
    int s = 0;
    for (int i = 0; i < n2-n1+2; i++)   {
        s += arr[i];
        if (ans==-1 || bs<s) {
            ans = i;
            bs = s;
        }
    }
    if (ans!=-1)
        return strarr[ans];
    return "";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        vector<vector<string>> reservations(n);

        for (int i = 0; i < n; i++) {
            reservations[i].resize(2);

            string reservations_row_temp_temp;
            getline(cin, reservations_row_temp_temp);

            vector<string> reservations_row_temp = split(rtrim(reservations_row_temp_temp));

            for (int j = 0; j < 2; j++) {
                string reservations_row_item = reservations_row_temp[j];

                reservations[i][j] = reservations_row_item;
            }
        }

        string result = solve(reservations);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}