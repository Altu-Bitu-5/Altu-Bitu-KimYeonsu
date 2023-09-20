//05_우선순위큐_도전문제2_프로그래머스>힙>디스크컨트롤러
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct CompareJob 
{
    bool operator()(const vector<int>& job1, const vector<int>& job2) {
        return job1[1] > job2[1];  // 작업 소요 시간이 적은 순으로 정렬
    }
};

int solution(vector<vector<int>> jobs) 
{
    int answer = 0;
    int current_time = 0;  // 현재 시간
    int job_index = 0;    // 처리 중인 작업의 인덱스
    priority_queue<vector<int>, vector<vector<int>>, CompareJob> pq; // 우선순위 큐

    sort(jobs.begin(), jobs.end());  // 작업 요청 시간 순으로 정렬

    while (job_index < jobs.size() || !pq.empty()) 
    {
        if (job_index < jobs.size() && current_time >= jobs[job_index][0]) 
        {
            pq.push(jobs[job_index]);
            job_index++;
            continue;
        }

        if (!pq.empty()) 
        {
            vector<int> job = pq.top();
            pq.pop();
            current_time += job[1];
            answer += current_time - job[0];
        } 
        else {
            current_time = jobs[job_index][0];
        }
    }

    return answer / jobs.size(); // 평균 계산
}
