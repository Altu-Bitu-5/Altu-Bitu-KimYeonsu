//그리디알고리즘 필수3: 18111 마인크래프트
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() 
{
    //입력  
    int N, M, B;
    cin >> N >> M >> B;

    vector<vector<int>> ground(N, vector<int>(M));
  
    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < M; j++) {
            cin >> ground[i][j];
        }
    }

    int min_time = 1e9; // 초기 최소 시간을 큰 값으로 설정
    int max_height = 0;

    for (int target_height = 0; target_height <= 256; target_height++) 
    {
        int time = 0; // 시간 초기화
        int blocks_in_inventory = B;

        for (int i = 0; i < N; i++) 
        {
            for (int j = 0; j < M; j++) 
            {
                int diff = ground[i][j] - target_height;
                if (diff > 0) 
                {
                    time += diff * 2; // 블록 제거 시간
                    blocks_in_inventory += diff; // 인벤토리에 블록 추가
                } 
                else if (diff < 0) 
                {
                    time += -diff; // 블록 추가 시간
                    blocks_in_inventory -= -diff; // 인벤토리에서 블록 소비
                }
            }
        }

        if (blocks_in_inventory >= 0 && time <= min_time) 
        {
            // 인벤토리에 충분한 블록이 있고, 최소 시간을 갱신하는 경우
            min_time = time;
            max_height = target_height;
        }
    }

    cout << min_time << " " << max_height << "\n";

    return 0;
}
