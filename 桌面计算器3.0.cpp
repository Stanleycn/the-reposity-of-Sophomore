/** 
*****************
* program:
*     END                  //END is end-of-input
*     expr_list END
* expr_list:
*     expression PRINT     // PRINT is semicolon
*     expression PRINT expr_list
* expression:
*     expression + term
*     expression - term
*     term
* term:
*     term / primary
*     term * primary
*     primary
* primary:
*     NUMBER
*     NAME    				// this is variable
*     NAME = expression
*     - primary
*     ( expression )
*/
#include<iostream>
#include<string>
#include<map>
#include<cctype>
using namespace std;

// ��token�����ǵ��ַ�����Ӧ��������ʾ���������ȷ�����Ч��
// ���ܰ���ʹ���Ŵ�ϵͳ���ˡ�
enum Token_value {
    NAME, NUMBER, END, PLUS='+',
    MINUS='-', MUL='*', DIV='/',
    PRINT=';', ASSIGN='=', LP='(', RP=')',
};
//���һ�ε���get_token������ֵ������curr_tok���ҵ� 
Token_value curr_tok = PRINT;
// ÿ������������һ��bool���� 
double expr(bool);
double term(bool);
double prim(bool);
Token_value get_token();
double error(const string&);
map<string, double> table;

// ָ���ú����Ƿ���Ҫ����get_token()ȥȡ����һ������
// expr����Ӽ���һֱ�����ǼӼ�����left
double expr(bool get) {
    double left = term(get);
    for(;;) {
        switch (curr_tok){
        case PLUS:
            left += term(true);
            break;
        case MINUS:
            left -= term(true);
            break;
        default:
            return left;
        }
    }
}

// ����term����˳������õķ�ʽ��expr()������һ��
double term(bool get) {
    double left = prim(get);
    for(;;) {
        switch (curr_tok){
        case MUL:
            left *= prim(true);
            break;
        case DIV:
            if (double d = prim(true)) {
                left /= d;
                break;
            }
            return error("divide by 0");
        default:
            return left;
        }
    }
}
//ʹ���ò�ν������һ�㣬�Ҳ�����ѭ�� 
double number_value;
string string_value;

// prim���������ķ�ʽ����expr��term
double prim(bool get) {           //��������� 
    if (get) get_token();

    switch(curr_tok) {
    case NUMBER: {              //���㳣�� 
        double v = number_value;
        get_token();
        return v;
    }
    case NAME: {
        double& v = table[string_value];
        if (get_token() == ASSIGN) v = expr(true);
        return v;
    }
    case MINUS:            //һԪ 
        return -prim(true);
    case LP: {                //�Ե������� 
        double e = expr(true);
        if (curr_tok != RP) return error(" ) expected");
        get_token();
        return e;
    }
    default:                 
        return error("primary expected");
    }
}

Token_value get_token() {
    char ch;
    
    do { // �ͼ����룬�Ľ�����
        if(!cin.get(ch)) return curr_tok = END;
    } while(ch != '\n' && isspace(ch));

    switch(ch) {
    case 0:
        return curr_tok=END;
    case '\n':
        return curr_tok=PRINT;
    case '+':
    case '-':
    case '*':
    case '/':
    case ';':
    case '(':
    case ')':
    case '=':
        return curr_tok = Token_value(ch);
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9':
    case '.':
        cin.putback(ch);
        cin>>number_value;
        return curr_tok = NUMBER;
    default:
        if (isalpha(ch)) {
            string_value = ch;
            while(cin.get(ch) && isalnum(ch)) string_value.push_back(ch);
            cin.putback(ch);
            return curr_tok = NAME;
        }
        error("bad token");
        return curr_tok = PRINT;
    }
}
int no_of_errors;
double error(const string& s) {
    no_of_errors ++;
    cerr<<"error: "<<s<<'\n';
    return 1;
}
int main()
{
    table["pi"] = 3.1415926535897932385;
    table["e"] = 2.7182818284590452354;

    while(cin) {
        get_token();
        if(curr_tok == END) break;
        if(curr_tok == PRINT) continue;
        cout<<expr(false)<<'\n';
    }
    return no_of_errors;
}
