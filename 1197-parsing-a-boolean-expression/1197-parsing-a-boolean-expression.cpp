class Solution {
public:
    bool parseBoolExpr(string exp)
    {
        stack<char> st;
        for(char ch : exp)
        {
            if(ch==',')
                continue;
            if(ch != ')')
                st.push(ch);
            else
            {
                int trueCount=0, falseCount=0;
                while(st.top() != '(')
                {
                    char tp = st.top(); st.pop();
                    if(tp=='f')
                        falseCount++;
                    else if(tp=='t')
                        trueCount++;
                }
                st.pop();
                char c = st.top(); st.pop();
                switch(c)
                {
                    case '&':
                        falseCount ? st.push('f') : st.push('t');
                        break;
                    case '|':
                        trueCount ? st.push('t') : st.push('f');
                        break;
                    case '!':
                        falseCount ? st.push('t') : st.push('f');
                        break;
                    default : //error
                }

            }
        } 
        return st.top()=='t' ? true : false;   
    }
};