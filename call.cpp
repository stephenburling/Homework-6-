#include <iostream>
#include <string>
#include "dlist.h"

struct Member {
    int time_stamp;
    std::string name;
    std::string level;
    int call_duration;
};
/*
void ReadCalls(Dlist<Member>& caller_queue) {
    Dlist<Member> new_list;
    while (!caller_queue.IsEmpty()) {
        Member current_member = caller_queue.RemoveBack();
        if (current_member.time_stamp != 0) {
            current_member.time_stamp = current_member.time_stamp - 1;
            new_list.InsertFront(current_member);
        }
        else {
            if (current_member.level == "none") {
                std::cout << "Call from " << current_member.name << " a regular member" << std::endl;
            }
            else {
                std::cout << "Call from " << current_member.name << " a " << current_member.level << " member" << std::endl;
            }
        }
        if (caller_queue.IsEmpty()) {
            caller_queue = new_list;
            break;
        }
    }
}
*/

int BusyCallReader(Dlist<Member>& caller_queue, int caller_duration, std::string name, int ticks) {
    for (int i = 0; i < caller_duration; i++) {
        int spot = 0;
        Dlist<Member> new_list;
        while (!caller_queue.IsEmpty()) {
            Member current_member = caller_queue.RemoveBack();
            if (current_member.time_stamp != ticks) {
                new_list.InsertFront(current_member);
                spot++;
            }
            else {
                if (current_member.level == "none") {
                    std::cout << "Call from " << current_member.name << " a regular member" << std::endl;
                }
                else {
                    std::cout << "Call from " << current_member.name << " a " << current_member.level << " member" << std::endl;
                }
            }
            if (caller_queue.IsEmpty()) {
                caller_queue = new_list;
                break;
            }
        }
        if (i == 0) {
            std::cout << "Answering call from " << name << std::endl;
        }
        if ((i + 1) != caller_duration) {
            ticks++;
            std::cout << "Starting tick #" << ticks << std::endl;
        }
        
    }
    return ticks;
}

void AnswerDriver(Dlist<Member>& caller_queue, Dlist<Member>& platinum_queue, Dlist<Member>& gold_queue, Dlist<Member>& silver_queue, Dlist<Member>& none_queue) {
    bool queue_cleared = false;
    int ticks = 0;
    std::cout << "Starting tick #" << ticks << std::endl;
    while (!queue_cleared) {

        queue_cleared = true;
        bool call_reader_ran = false;

        if (!platinum_queue.IsEmpty() && (call_reader_ran == false)) {
            queue_cleared = false;
            bool search_queue = true;
            Dlist<Member> temp_list;
            while (search_queue == true) {
                Member current_member = platinum_queue.RemoveBack();
                //std::cout << "   Checking member " << current_member.name << " with time stamp number     " << current_member.time_stamp << "      ANSWER_DRIVER" << std::endl;
                if (ticks >= current_member.time_stamp) {
                    ticks = BusyCallReader(caller_queue, current_member.call_duration, current_member.name, ticks);
                    call_reader_ran = true;
                    search_queue = false;
                }
                else {
                    temp_list.InsertBack(current_member);
                }
                if (platinum_queue.IsEmpty()) {
                    while (!temp_list.IsEmpty()) {
                        platinum_queue.InsertFront(temp_list.RemoveBack());
                    }
                    search_queue = false;
                }
            }
        }

        if (!gold_queue.IsEmpty() && (call_reader_ran == false)) {
            queue_cleared = false;
            bool search_queue = true;
            Dlist<Member> temp_list;
            while (search_queue == true) {
                Member current_member = gold_queue.RemoveBack();
                //std::cout << "   Checking member " << current_member.name << " with time stamp number     " << current_member.time_stamp << "      ANSWER_DRIVER" << std::endl;
                if (ticks >= current_member.time_stamp) {
                    ticks = BusyCallReader(caller_queue, current_member.call_duration, current_member.name, ticks);
                    call_reader_ran = true;
                    search_queue = false;
                }
                else {
                    temp_list.InsertBack(current_member);
                }
                if (gold_queue.IsEmpty()) {
                    while (!temp_list.IsEmpty()) {
                        gold_queue.InsertFront(temp_list.RemoveBack());
                    }
                    search_queue = false;
                }
            }
        }

        if(!silver_queue.IsEmpty() && (call_reader_ran == false)) {
            queue_cleared = false;
            bool search_queue = true;
            Dlist<Member> temp_list;
            while (search_queue == true) {
                Member current_member = silver_queue.RemoveBack();
                //std::cout << "   Checking member " << current_member.name << " with time stamp number     " << current_member.time_stamp << "      ANSWER_DRIVER" << std::endl;
                if (ticks >= current_member.time_stamp) {
                    ticks = BusyCallReader(caller_queue, current_member.call_duration, current_member.name, ticks);
                    call_reader_ran = true;
                    search_queue = false;
                }
                else {
                    temp_list.InsertBack(current_member);
                }
                if (silver_queue.IsEmpty()) {
                    while (!temp_list.IsEmpty()) {
                        silver_queue.InsertFront(temp_list.RemoveBack());
                    }
                    search_queue = false;
                }
            }
        }

        if (!none_queue.IsEmpty() && (call_reader_ran == false)) {
            queue_cleared = false;
            bool search_queue = true;
            Dlist<Member> temp_list;
            while (search_queue == true) {
                Member current_member = none_queue.RemoveBack();
                //std::cout << "   Checking member " << current_member.name << " with time stamp number     " << current_member.time_stamp << "      ANSWER_DRIVER" << std::endl;
                if (ticks >= current_member.time_stamp) {
                    ticks = BusyCallReader(caller_queue, current_member.call_duration, current_member.name, ticks);
                    call_reader_ran = true;
                    search_queue = false;
                }
                else {
                    temp_list.InsertBack(current_member);
                }
                if (none_queue.IsEmpty()) {
                    while (!temp_list.IsEmpty()) {
                        none_queue.InsertFront(temp_list.RemoveBack());
                    }
                    search_queue = false;
                }
            }
        }

        if (queue_cleared == false) {
            ticks++;
            std::cout << "Starting tick #" << ticks << std::endl;
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
        std::cin >> new_member.time_stamp;
        std::cin >> new_member.name;
        std::cin >> new_member.level;
        std::cin >> new_member.call_duration;

        member_stack.InsertFront(new_member);
    }

    SortMembers(member_stack);
    return 0;
}