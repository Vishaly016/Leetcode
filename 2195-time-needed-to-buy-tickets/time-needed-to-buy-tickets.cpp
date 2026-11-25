class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<int> q;
        int s = tickets.size();
        for(int i=0; i<s; i++){
            q.push(i);
        }

        int time = 0;

        while(tickets[k]){
            time++;
            tickets[q.front()]--;
            if(tickets[q.front()]==0) q.pop();
            else{
                q.push(q.front());
                q.pop();
            }
        }
        return time;
    }
};