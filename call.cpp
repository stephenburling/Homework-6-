#include <iostream>
#include <string>
#include "dlist.h"

struct Member {
    int number_of_ticks;
    std::string name;
    std::string level;
    int call_duration;
};

int CallReader(Dlist<Member>& caller_queue, int caller_duration, std::string name, int ticks) {
    for (int i = 0; i < caller_duration; i++) {
        while (!caller_queue.IsEmpty()) {
            Dlist<Member> new_list;
            Member current_member = caller_queue.RemoveBack();
            if (current_member.number_of_ticks != 0) {
                current_member.number_of_ticks = current_member.number_of_ticks - 1;
                new_list.InsertBack(current_member);
            }
            else {
                std::cout << "Call from " << current_member.name << " a " << current_member.level << " member" << std::endl;
            }
            if (caller_queue.IsEmpty()) {
                caller_queue = new_list;
                break;
            }
        }
        if (i == 0) {
            std::cout << "Answering call from " << name << std::endl;
        }
        ticks++;
        std::cout << "Starting tick #" << ticks << std::endl;
    }
      
    return ticks;
}

void AnswerDriver(Dlist<Member>& caller_queue, Dlist<Member>& platinum_queue, Dlist<Member>& gold_queue, Dlist<Member>& silver_queue, Dlist<Member>& none_queue) {
    bool queue_cleared = false;
    int ticks = 0;
    std::cout << "Starting tick #" << ticks << std::endl;
    while (!queue_cleared) {
        if (!platinum_queue.IsEmpty()) {
            Member current_member = platinum_queue.RemoveBack();

            ticks = CallReader(caller_queue, current_member.call_duration, current_member.name, ticks);

        }else if (!gold_queue.IsEmpty()) {
            Member current_member = gold_queue.RemoveBack();

            ticks = CallReader(caller_queue, current_member.call_duration, current_member.name, ticks);

        } else if(!silver_queue.IsEmpty()) {
            Member current_member = silver_queue.RemoveBack();

            ticks = CallReader(caller_queue, current_member.call_duration, current_member.name, ticks);

        }else if (!none_queue.IsEmpty()) {
            Member current_member = none_queue.RemoveBack();

            ticks = CallReader(caller_queue, current_member.call_duration, current_member.name, ticks);

        }
        else {
            queue_cleared = true;
        }
    }
}

void SortMembers(Dlist<Member>& member_stack){
    Dlist<Member> call_queue;
    Dlist<Member> platinum_queue;
    Dlist<Member> gold_queue;
    Dlist<Member> silver_queue;
    Dlist<Member> none_queue;

    while (!member_stack.IsEmpty()) {
        Member new_member = member_stack.RemoveFront();
        
        if (new_member.level == "platinum") {
            platinum_queue.InsertBack(new_member);
        }else if (new_member.level == "gold") {
            gold_queue.InsertBack(new_member);
        }else if (new_member.level == "silver") {
            silver_queue.InsertBack(new_member);
        }else if (new_member.level == "none") {
            none_queue.InsertBack(new_member);
        }
        call_queue.InsertBack(new_member);
    }
    AnswerDriver(call_queue, platinum_queue, gold_queue, silver_queue, none_queue);
}

int main() {
    Dlist<Member> member_stack;
    std::string number_of_calls;
    std::cin >> number_of_calls;

    for (int i = 0; i < stoi(number_of_calls); i++) {
        Member new_member;
        std::cin >> new_member.number_of_ticks;
        std::cin >> new_member.name;
        std::cin >> new_member.level;
        std::cin >> new_member.call_duration;
        member_stack.InsertFront(new_member);
    }

    SortMembers(member_stack);
    return 0;
}