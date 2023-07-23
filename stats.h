#include <vector>
#include <math.h>
#include <cmath>
#include <numeric>

namespace Statistics {
    
    struct Stats
    {
        double average;
        double max;
        double min;
    };
    
    Stats ComputeStatistics(const std::vector<double>&);

    template <typename T>
	//find Average
    T FindAverage(const std::vector<T>& vec) {
        T sum = std::accumulate(vec.begin(), vec.end(), 0.0);
        if (sum == 0)
            return NAN;
        else
            return sum / static_cast<double>(vec.size());
    }

    template <typename T>
	//Find Maximum
    T FindMax(const std::vector<T>& vec) {
        return *max_element(vec.begin(), vec.end());
    }

    template <typename T>
	//Find Minimum
    T FindMin(const std::vector<T>& vec) {
        return *min_element(vec.begin(), vec.end());
    }
}

class IAlerter
{
public:
	virtual void sendAlert() = 0;
};

class EmailAlert : public IAlerter
{
public:
	virtual void sendAlert() override;
    bool emailSent = false;
};


class LEDAlert :public IAlerter
{
public:
	virtual void sendAlert() override;
    bool ledGlows = false;
};


class StatsAlerter
{
public:
	StatsAlerter(float maxThreshold, std::vector<IAlerter*> alerters);
	void checkAndAlert(const std::vector<double>& v);
private:
	float maxThreshold;
	std::vector<IAlerter*> alerters;
};
