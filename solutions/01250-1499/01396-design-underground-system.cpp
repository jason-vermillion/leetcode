// https://leetcode.com/problems/design-underground-system/
// 1396. Design Underground System
class UndergroundSystem {
    map<int, pair<string, int>> checkins;
    map<string, pair<int, int>> times;
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        checkins[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        string trip;
        int duration;
        
        const auto &start = checkins[id];
        duration = t - start.second;
        trip = start.first + "-" + stationName;
        times[trip].first += duration;
        times[trip].second++;
    }
    
    double getAverageTime(string startStation, string endStation) {
        double avgTime;
        string trip = startStation + "-" + endStation;
        
        avgTime = (double)times[trip].first / times[trip].second;
        
        return avgTime;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */