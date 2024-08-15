/**
 * @file accounts_merge.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-08-14
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <bits/stdc++.h>
#include <vector>
#include <unordered_map>
using namespace std;

/*
    Given a list of accounts where each element accounts[i] is a list of strings, where the first element accounts[i][0] is a name, 
    and the rest of the elements are emails representing emails of the account.
    Now, we would like to merge these accounts. Two accounts definitely belong to the same person if there is some common email to both accounts. 
    Note that even if two accounts have the same name, they may belong to different people as people could have the same name. A person can have any number of accounts initially, but all of their accounts definitely have the same name.

    After merging the accounts, return the accounts in the following format: the first element of each account is the name, and the rest of the elements are emails in sorted order. 
    The accounts themselves can be returned in any order.

    Example 1:
    Input: accounts = [["John","johnsmith@mail.com","john_newyork@mail.com"],["John","johnsmith@mail.com","john00@mail.com"],["Mary","mary@mail.com"],["John","johnnybravo@mail.com"]]
    Output: [["John","john00@mail.com","john_newyork@mail.com","johnsmith@mail.com"],["Mary","mary@mail.com"],["John","johnnybravo@mail.com"]]
    
    Explanation:
    The first and second John's are the same person as they have the common email "johnsmith@mail.com".
    The third John and Mary are different people as none of their email addresses are used by other accounts.
    We could return these lists in any order, for example the answer [['Mary', 'mary@mail.com'], ['John', 'johnnybravo@mail.com'], 
    ['John', 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com']] would still be accepted.
    
    Example 2:
    Input: accounts = [["Gabe","Gabe0@m.co","Gabe3@m.co","Gabe1@m.co"],["Kevin","Kevin3@m.co","Kevin5@m.co","Kevin0@m.co"],["Ethan","Ethan5@m.co","Ethan4@m.co","Ethan0@m.co"],["Hanzo","Hanzo3@m.co","Hanzo1@m.co","Hanzo0@m.co"],["Fern","Fern5@m.co","Fern1@m.co","Fern0@m.co"]]
    Output: [["Ethan","Ethan0@m.co","Ethan4@m.co","Ethan5@m.co"],["Gabe","Gabe0@m.co","Gabe1@m.co","Gabe3@m.co"],["Hanzo","Hanzo0@m.co","Hanzo1@m.co","Hanzo3@m.co"],["Kevin","Kevin0@m.co","Kevin3@m.co","Kevin5@m.co"],["Fern","Fern0@m.co","Fern1@m.co","Fern5@m.co"]]
*/

/*
    Plan
    Scroll through accounts one by one

    keep a map of emails and their current index in the solution
    If I am trying to add a new account and the email is already in the solution
        Add that account merge those 2 accounts
    else add the account to the solution

*/


class Solution {
public:
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, int> email_storage; //Map of Email : Solution[Index]
        vector<vector<string>> solution;

        for(int i = 0; i < accounts.size(); i++){
            bool merge = false;
            int index_to_update;

            //Check if it is not in solution
            for(int j = 1; j < accounts[i].size(); j++){ //start from email
                if(email_storage.find(accounts[i][j]) != email_storage.end()){
                    //update merge
                    merge = true;

                    //found it in map
                    int index_to_append = email_storage[accounts[i][j]];

                    //Add all emails to that index
                    for(int k = 1; k < accounts[i].size(); k++){
                        solution.at(index_to_append).push_back(accounts[i][k]);   //only add emails that are not there yet                     
                    }

                    index_to_update = index_to_append; //this will be my update email
                    break;
                }
            }

            //if there was no merge, add this to solution
            if(merge == false){
                solution.push_back(accounts[i]);
            }

            //update map
            int email_index = (merge)? index_to_update : solution.size()-1; //either the updated index or the last addition to solution

            //Add all emails to that index
            for(int k = 1; k < accounts[i].size(); k++){
                email_storage[accounts[i][k]] = email_index;                       
            }

            //ensure emails are in sorted order
            sort(solution[email_index].begin()+1, solution[email_index].end());

            //ensure unique solutions by removing duplicates
            auto last = unique(solution[email_index].begin()+1, solution[email_index].end());
            solution[email_index].erase(last, solution[email_index].end());
        } 

        return solution;
    }
};


/**
 * @brief ChatGPT Solution
 * 
 */