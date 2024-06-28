//
// Created by Azure on 2024/6/25.
//
#include "../include/Recursive.h"
Recursive::Recursive() {//构造函数
    heigh = 0;
    low = 0;
    step = 0;
    grid = 0;
    inputtap = {};
    worktap.resize(1);
    output = {-1};
    stack<Frame> intstk;
    work_stack.swap(intstk);
    current_in = 0;
    current_work = 0;
}

void Recursive::initwork(vector<int> input,int find) {
    if(input.size()==0) {
        cout<<"error input"<<endl;
    }else {
        sort(input.begin(),input.end());
        this->grid = 0;
        this->step = 0;
        this->current_in = 0;
        this->inputtap = input;
        this->low = 0;
        this->heigh = input.size()-1;
        // local[0] = low;
        // local[1] = heigh;
        inputtap.insert(inputtap.begin(),find);
        // inputtap.insert(inputtap.begin(),heigh);
        // inputtap.insert(inputtap.begin(),low);
        work_stack.push({low,heigh,(low+heigh)/2});
    }
}

void Recursive::showinputtap() {
    for(auto i =inputtap.begin();i<inputtap.end();i++) {
        cout<<"  "<<*i;
    }
    cout<<endl;
}

void Recursive::TuringStart() {
    scan();
}
void Recursive::scan() {
    int state = 2;
    while (state!=0&&!work_stack.empty()){
        step++;
        switch(state) {
            case 1:
                getstack();
                state = 2;
            break;
            case 2:
                state = compareHeigh();
            break;
            // case 3:
            //     getMiddle();//用于表示进行了一步，在这没有实际作用
            //     state = 4;
            // break;
            case 4:
                findMiddle();
                state = 5;
            break;
            case 5:
                state = compareMiddle();
            break;
            case 6:
                updateLow();
                state = 8;
            break;
            case 7:
                updateHigh();
                state = 8;
            break;
            case 8:
                callstack();
                state = 1;
            break;
            case 9:
                success();
                state = 0;
            break;
            default:
                cout<<"ERROR STATE";
            break;
        }
    }
    stop();
}

void Recursive::readlow() {     //状态1-
    low = work_stack.top().low;
}

void Recursive::getstack() {//状态1-
    low = work_stack.top().low;
    heigh = work_stack.top().high;    //读取heigh
}


int Recursive::compareHeigh() {     //状态2
    if(low>heigh) {
        return 0;
    }
    return 4;
}
int Recursive::findMiddle() {      //状态4
    current_in = work_stack.top().mid+1;
    int middle = inputtap[current_in];//
    current_work = 0;
    worktap[0] = middle;
    grid = 1;
    return middle;
}
int Recursive::getMiddle() {        //状态3-
    int middle_index =  work_stack.top().mid;
    return middle_index;
}
int Recursive::compareMiddle() {      //状态5
    int mid = worktap[0];
    current_in = 0;
    int target = inputtap[0];
    int state;
    if (mid == target) {
        state = 9;
    } else if (mid < target) {
        state = 6;
    } else {
        state = 7;
    }
    return state;
}

void Recursive::updateLow() {       //状态6
    low = work_stack.top().mid + 1;
}

void Recursive::updateHigh() {       //状态7
    heigh = work_stack.top().mid - 1;
}
void Recursive::callstack() {       //状态8
    work_stack.push({low,heigh,(low+heigh)/2});
    cout<<"push"<<endl;
}

void Recursive::success() {       //状态9
    //output.push_back(worktap[0]);
    output[0] = worktap[0];
}

int Recursive::stop() {
    cout << "Search complete. Steps: " << step << ". Output: ";
    for (int index : output) {
        cout << index << " ";
    }
    cout << endl;
    cout << "Work tape: ";
    for (int i = 0; i < worktap.size(); i++) {
        cout << worktap[i] << " ";
    }
    cout << endl;
    cout<<"stack:"<<endl;
    while(!work_stack.empty()) {
        cout<<"low: "<<work_stack.top().low<<" high: "<<work_stack.top().high<<" mid: "<<work_stack.top().mid;
        cout<<endl;
        work_stack.pop();
    }
    return 0;
}

void Recursive::showstack() {
    stack<Frame> temp = work_stack;
    Frame t ;
    static int time = 0;
    time++;
    cout<<"time: "<<time<<endl;
    while(!temp.empty()) {
        t = temp.top();
        temp.pop();
        cout<<"low "<<t.low<<" high "<<t.high<<" mid "<<t.mid<<endl;
    }
    cout<<"------"<<endl;
}

// int BinarySearch(int left,int right,int a[],const int x) //主函数
// {
//     if(left<=right)  //找到left，并且比较right
//     {
//         int middle = (left+right)/2; //计算得到middle
//         if(a[middle]==x) //取middle值，进行判断
//         {
//             return middle;   //success
//         }
//         else if(x>a[middle])
//         {
//             return BinarySearch(middle+1,right,a,x); //压栈递归下一层
//         }
//         else
//             return BinarySearch(left,middle-1,a,x);//压栈递归下一层
//     }
//     return -1;   //stop
// }

Recursive::~Recursive() {
    cout<<endl<<"Destructor called"<<endl;
}

