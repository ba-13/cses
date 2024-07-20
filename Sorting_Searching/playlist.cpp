/*
 * @Author: ba-13
 * @Date:   2024-07-20 00:53:46
 * @Last Modified by:   ba-13
 * @Last Modified time: 2024-07-21 01:02:24
 https://cses.fi/problemset/task/1141
 Inspiration from Kadane's algorithm
 */

#ifdef LOCAL
#include "../_header.hpp"
#else
#include <bits/stdc++.h>
#define deb(x) ;
#endif
using namespace std;

// this gets TLE in one of the testcases
int get_longest_unique_subsequence_arr(vector<int> &songs)
{
    // we find longest subsequence at each position if it was the last
    int best = 0, curr = 0;
    int n = songs.size();
    set<int> song_set;
    vector<int> song_series;
    for (int i = 0; i < n; i++)
    {
        // check the 2 conditions
        // either this element alone is included for this location's longest
        // or this location and the previous location's best
        if (song_set.find(songs[i]) != song_set.end())
        {
            // this element is already present in the song set
            // can't include this element in curr going set
            // clear set and series until this element
            int idx = song_series.size() - 1;
            while (song_series[idx] != songs[i])
                idx--;
            // this should keep all songs from that index (inclusive)
            set<int> keep_songs(song_series.begin() + idx, song_series.end());
            // erase including the last seen position
            song_series.erase(song_series.begin(),
                              song_series.begin() + idx + 1);
            // insert the new song at end
            song_series.push_back(songs[i]);
            song_set.clear();
            song_set = keep_songs;
            curr = song_series.size();
        }
        else
        {
            song_set.insert(songs[i]);       // to store element
            song_series.push_back(songs[i]); // to store order
            curr += 1;
        }
        best = max(best, curr);
        deb(song_set);
        deb(song_series);
        deb(best);
    }
    return best;
}

int get_longest_unique_subsequence_map(vector<int> &songs)
{
    int start = 0;
    int max_length = 0;
    map<int, int> mp;
    int n = songs.size();

    for (int end = 0; end < n; end++)
    {
        if (mp.find(songs[end]) != mp.end())
        {
            // curr song present already
            if (mp[songs[end]] >= start)
                start = mp[songs[end]] + 1;
            mp[songs[end]] = end;
        }
        else
        {
            mp[songs[end]] = end;
        }
        max_length = max(max_length, end - start + 1);
    }
    return max_length;
}

int test()
{
    cerr << "Running test\n";
    vector<int> songs = {1, 2, 1, 3, 2, 7, 4, 2};
    assert(get_longest_unique_subsequence_map(songs) == 5);
    songs.clear();
    songs = {1, 2, 1, 1, 2, 3, 2, 7, 4, 2};
    assert(get_longest_unique_subsequence_map(songs) == 4);
    cerr << "Passed\n";
    return 0;
}

int main()
{
    int n;
    cin >> n;
    vector<int> songs(n);
    for (int i = 0; i < n; i++)
        cin >> songs[i];

    int answer = get_longest_unique_subsequence_map(songs);
    cout << answer << "\n";
    return 0;
}