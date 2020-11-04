#include <iostream>
#include <string>
#include "dlist.h"

/*
struct Member
    Declare int time_stamp
    Declare string name
    Declare string level
    Declare int call_duartion


int BusyCallReader(Dlist<Member>& caller_queue, int caller_duration, std::string name, int ticks)
    For the duration of answered member's call
        Create empty list called new_list
        While caller queue is not empty
            Pull member from caller queue
            if time stamp of current member is not equal to the tick count
                insert member into new_list
            else
                if current member's level is equal to "none"
                    Print "Call from " << current_member.name << " a regular member"
                else
                    Print "Call from " << current_member.name << " a " << current_member.level << " member"
            if caller queue is empty
                set caller queue to new_list
                break from while loop
        if for loop is on first loop
            Print "Answering call from " << name << endl;
        if next loop does not end the for loop
            increment ticks
                Print "Starting tick #" << ticks << endl
    return ticks


void AnswerDriver(Dlist<Member>& caller_queue, Dlist<Member>& platinum_queue, Dlist<Member>& gold_queue, Dlist<Member>& silver_queue, Dlist<Member>& none_queue)
    Create boolean called queue_cleared set to false
    Initialize int ticks to 0
    Print "Starting tick #" << ticks << endl;
    While queue_cleared is false
        set queue cleared to true
        create boolean named call_reader_ran set to false

        if platinum queue is not empty and is call reader has not been ran yet
            set queue_cleared to false
                create boolean search_queue set to true
                create temporary Dlist called temp_list
                While search_queue is true
                    Pull member from platinum queue
                    if ticks are greater of equal to timestamp of current member
                        set ticks equal to returned value after running BusyCallReader
                        set call_reader_ran to true
                        set search_queue to false
                    else
                        insert member back into queue
                    if platinum queue is empty
                        while temp_list is not empty
                            load temp_list members into platinum queue
                        set search_queue to false

        if gold queue is not empty and is call reader has not been ran yet
            set queue_cleared to false
                create boolean search_queue set to true
                create temporary Dlist called temp_list
                While search_queue is true
                    Pull member from gold queue
                    if ticks are greater of equal to timestamp of current member
                        set ticks equal to returned value after running BusyCallReader
                        set call_reader_ran to true
                        set search_queue to false
                    else
                        insert member back into queue
                    if gold queue is empty
                        while temp_list is not empty
                            load temp_list members into gold queue
                        set search_queue to false

        if silver queue is not empty and is call reader has not been ran yet
            set queue_cleared to false
                create boolean search_queue set to true
                create temporary Dlist called temp_list
                While search_queue is true
                    Pull member from silver queue
                    if ticks are greater of equal to timestamp of current member
                        set ticks equal to returned value after running BusyCallReader
                        set call_reader_ran to true
                        set search_queue to false
                    else
                        insert member back into queue
                    if silver queue is empty
                        while temp_list is not empty
                            load temp_list members into silver queue
                        set search_queue to false

        if none queue is not empty and is call reader has not been ran yet
            set queue_cleared to false
                create boolean search_queue set to true
                create temporary Dlist called temp_list
                While search_queue is true
                    Pull member from none queue
                    if ticks are greater of equal to timestamp of current member
                        set ticks equal to returned value after running BusyCallReader
                        set call_reader_ran to true
                        set search_queue to false
                    else
                        insert member back into queue
                    if none queue is empty
                        while temp_list is not empty
                            load temp_list members into none queue
                        set search_queue to false

        if queue_cleared is false
            increment ticks 
            Print "Starting tick #" << ticks << endl
            

void SortMembers(Dlist<Member>& member_stack)
    Create Member Dlist named caller_queue
    Create Member Dlist named platinum_queue
    Create Member Dlist named gold_queue
    Create Member Dlist named silver_queue
    Create Member Dlist named none_queue

    While passed stack of members is not empty
        Pull member from member_stack
        if member level is platinum
            insert member into platinum queue
        else if member level is gold
            insert member into gold queue
        else if member level is silver
            insert member into silver queue
        else if member level is none
            insert member into none queue
        insert member into call queue

    Call AnswerDriver with call_queue, platinum_queue, gold_queue, silver_queue, and none_queue


int main()
    Create Member Dlist called member_stack
    Set string number_of_calls equal to first input

    For the entire number of calls
        Create member called new_member
        take input for member timestamp
        take input for member name
        take input for member level
        take input for member call duration
        insert member into member_stack
    Call SortMembers
    Return 0
*/

struct Member {
    int time_stamp;
    std::string name;
    std::string level;
    int call_duration;
};

int BusyCallReader(Dlist<Member>& caller_queue, int caller_duration, std::string name, int ticks) {
    for (int i = 0; i < caller_duration; i++) {
        Dlist<Member> new_list;
        while (!caller_queue.IsEmpty()) {
            Member current_member = caller_queue.RemoveBack();
            if (current_member.time_stamp != ticks) {
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