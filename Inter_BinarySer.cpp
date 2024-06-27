#include "Inter_BinarySer.h"



TuringMachine::TuringMachine(const std::vector<int>& arr, int x)
    : steps(0), tapeSpace(0), intputtape(arr), target(x), state(INIT_LOW) {
    worktape.resize(arr.size() + 10, 0); // 初始化工作带，确保有足够的空间
}

int TuringMachine::execute() {
    // 初始化指针
    int low = 0;
    int high = intputtape.size() - 1;
    int mid = 0;
    int work = 0;
    int worksteps = 0;

    // 状态机执行
    while (true) {
        steps++; // 增加步数

        switch (state) {
        case INIT_LOW:
            worktape[worksteps++] = low;
            work = low;
            state = WRITE_LOW;
            break;

        case WRITE_LOW:
            low = work;
            state = INIT_HIGH;
            break;

        case INIT_HIGH:
            worktape[worksteps--] = high;
            work = high;
            state = WRITE_HIGH;
            break;

        case WRITE_HIGH:
            high = work;
            state = COMPARE_LOW;
            break;

        case COMPARE_LOW:
            if (low > high) {
                state = STOP;
            }
            else {
                state = CAI_MID;
            }
            break;

        case STOP:
            return -1; // 查找失败

        case CAI_MID:
            mid = low + (high - low) / 2;
            state = READ_MID;
            break;

        case READ_MID:
            worksteps += 2;
            worktape[worksteps] = mid;
            work = intputtape[mid];
            // 打印工作带内容
            for (int i = 0; i <= worksteps; i++) {
                cout << worktape[i] << " ";
            }
            cout << endl; // 加上换行符使输出更清晰
            if (worksteps > tapeSpace)
                tapeSpace = worksteps;
            worksteps -= 2;
            state = COMPARE_MID;
            break;

        case COMPARE_MID:
            if (work == target) {
                state = SUCCESS;
            }
            else if (work < target) {
                state = UPDATE_LOW;
            }
            else {
                state = UPDATE_HIGH;
            }
            break;

        case SUCCESS:
            return mid; // 查找成功

        case UPDATE_LOW:
            low = mid + 1;
            worktape[worksteps++] = low;
            worktape[worksteps--] = high;
            state = COMPARE_LOW;
            break;

        case UPDATE_HIGH:
            high = mid - 1;
            worktape[worksteps++] = low;
            worktape[worksteps--] = high;
            state = COMPARE_LOW;
            break;
        }
    }
}
