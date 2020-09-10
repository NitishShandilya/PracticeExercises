//
// Created by Nitish Mohan Shandilya on 9/10/20.
//

// Fruits promotion
// Given shopping cart and the lucky sequence, determine if the
// customer is the winner or not

bool isWinner(vector<vector<string>>& codeList, vector<string>& shoppingCart) {
    // go over codeList and see if the sequence is there. If not break immediately and move
    // in shopping cart. Maintain a match variable. Return that.
    if (shoppingCart.empty()) return false;
    if (codeList.empty()) return true;

    int i=0, j=0;
    while (i<codeList.size() && j<shoppingCart.size()) {
        vector<string>& code = codeList[i];
        bool noMatch = false;
        for (int k=0; k<code.size(); ++k) {
            if (!(code[k] == shoppingCart[j+k] || code[k] == "anything")) {
                noMatch = true;
                break;
            }
        }
        if (noMatch) {
            ++j;
        } else {
            j += code.size();
            ++i;
        }
    }
    if (i == codeList.size())
        return true;
    return false;
}

int main() {

    vector<vector<string>> codeList = {{"apple", "apple"}, {"banana", "orange", "grape"}};
    vector<string> shoppingCart = {"apple", "apple", "banana", "orange", "orange", "banana", "orange", "grape"};

    vector<vector<string>> codeList1 = { { "apple", "apple" }, { "banana", "anything", "banana" } };
        vector<string> shoppingCart1 = {"orange", "apple", "apple", "banana", "orange", "banana"};
        vector<vector<string>> codeList2 = { { "apple", "apple" }, { "banana", "anything", "banana" } };
        vector<string> shoppingCart2 = {"banana", "orange", "banana", "apple", "apple"};
        vector<vector<string>> codeList3 = { { "apple", "apple" }, { "banana", "anything", "banana" } };
        vector<string> shoppingCart3 = {"apple", "banana", "apple", "banana", "orange", "banana"};
        vector<vector<string>> codeList4 = { { "apple", "apple" }, { "apple", "apple", "banana" } };
        vector<string> shoppingCart4 = {"apple", "apple", "apple", "banana"};
        vector<vector<string>> codeList5 = { { "apple", "apple" }, { "banana", "anything", "banana" } };
        vector<string> shoppingCart5 = {"orange", "apple", "apple", "banana", "orange", "banana"};
        vector<vector<string>> codeList6 = { { "apple", "apple" }, { "banana", "anything", "banana" }  };
        vector<string> shoppingCart6 = {"apple", "apple", "orange", "orange", "banana", "apple", "banana", "banana"};
        vector<vector<string>> codeList7= { { "anything", "apple" }, { "banana", "anything", "banana" }  };
        vector<string> shoppingCart7 = {"orange", "grapes", "apple", "orange", "orange", "banana", "apple", "banana", "banana"};
        vector<vector<string>> codeList8 = {{"apple", "orange"}, {"orange", "banana", "orange"}};
        vector<string> shoppingCart8 = {"apple", "orange", "banana", "orange", "orange", "banana", "orange", "grape"};
        vector<vector<string>> codeList9= { { "anything", "anything", "anything", "apple" }, { "banana", "anything", "banana" }  };
        vector<string> shoppingCart9 = {"orange", "apple", "banana", "orange", "apple", "orange", "orange", "banana", "apple", "banana"};

    cout << isWinner(codeList, shoppingCart);
}
