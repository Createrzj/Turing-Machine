#include "Recursive.h"
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
        worktap.resize(1);
        output = {-1};
        stack<Frame> intstk;
        work_stack.swap(intstk);
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
        inputtap.insert(inputtap.begin(),heigh);
        inputtap.insert(inputtap.begin(),low);
        //work_stack.push({low,heigh,(low+heigh)/2});
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
    int state = 1;
    while (state!=0){
        step++;
        switch(state) {
            case 1:
                readlow();
                state = 2;
            break;
            case 2:
                state = compareHeigh();
            break;
            case 3:
                getMiddle();
                state = 4;
            break;
            case 4:
                findMiddle();
                state = 5;
            break;
            case 5:
                state = compareMiddle();
            // break;
            // case 6:
            //     updateLow();
            //     state = 8;
            // break;
            // case 7:
            //     updateHigh();
            //     state = 8;
            // break;
            // case 8:
            //     callstack();
            //     state = 1;
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
    current_in = 0;
    low = inputtap[current_in];
    current_in++;
}

void Recursive::getstack() {//状态1-
    low = work_stack.top().low;
    heigh = work_stack.top().high;    //读取heigh
}

int Recursive::compareHeigh() {     //状态2
    heigh = inputtap[current_in];
    if(low>heigh) {
        return 0;
    }
    return 3;
}
int Recursive::findMiddle() {      //状态4
    int middle = inputtap[current_in];//
    current_work = 0;
    worktap[0] = middle;
    grid = 1;
    return middle;
}
int Recursive::getMiddle() {        //状态3-
    int middle_index =  (heigh+low)/2+3;
    current_in = middle_index;
    return middle_index;
}
int Recursive::compareMiddle() {      //状态5
    int mid = worktap[0];
    current_in = 2;
    int target = inputtap[2];
    int state;
    if (mid == target) {
        state = 9;
    } else if (mid < target) {
        state = 1;
        updateLow();
        callstack();
    } else {
        state = 1;
        updateHigh();
        callstack();
    }
    return state;
}

void Recursive::updateLow() {       //状态6
    low = worktap[0] + 1;
}

void Recursive::updateHigh() {       //状态7
    heigh = worktap[0] - 1;
}
void Recursive::callstack() {       //状态8
    work_stack.push({inputtap[0],inputtap[1],(inputtap[0]+inputtap[1])/2});
    inputtap[0] = low;inputtap[1] = heigh;
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

Recursive::~Recursive() {
    cout<<endl<<"Destructor called"<<endl;
}