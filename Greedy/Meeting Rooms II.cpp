// Approach: 2 pointer and greedy
class Solution {
public:
    int minMeetingRooms(vector<int> &start, vector<int> &end) {
        int n = start.size();

        sort(start.begin(), start.end());
        sort(end.begin(), end.end());

        int i = 0, j = 0;
        int rooms = 0, maxRooms = 0;

        while(i < n) {
            // New meeting starts before previous ends → need room
            if(start[i] < end[j]) {
                rooms++;
                i++;
            }
            // A meeting ended → free a room
            else {
                rooms--;
                j++;
            }
            maxRooms = max(maxRooms, rooms);
        }

        return maxRooms;
    }
};
