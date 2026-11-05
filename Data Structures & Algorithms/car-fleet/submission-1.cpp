class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {

        //{position, speed}
        vector<pair<int, int>> cars;

        for(int i = 0; i < speed.size(); i++){
            cars.push_back({position[i], speed[i]});
        }

        //sort the cars array from greater to smallest position
        sort(cars.rbegin(), cars.rend());

        stack<double> st;

        for(int i = 0; i < speed.size(); i++){
            double time = (double)(target - cars[i].first)/cars[i].second;

            //if the stack is empty
            //or the the current car takes more time 
            //to reach the end than the previous car
            //then form a new fleet.
            if(st.empty() || time > st.top()){
                st.push(time);
            }

            //otherwise they form a group with the previous one.
        }

        return st.size();

        
    }
};
