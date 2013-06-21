// Source: http://www.daniweb.com/software-development/cpp/code/427500/calculator-using-shunting-yard-algorithm#
// Author: Jesse Brown
// Modifications: Brandon Amos

#ifndef _SHUNTING_YARD_H
#define _SHUNTING_YARD_H

#include <map>
#include <stack>
#include <string>
#include <vector>

struct TokenBase { 
  virtual ~TokenBase() {}
};

template< class T > class Token : public TokenBase {
public:
  Token (T t) : val(t) {}
  T val;
private:
};

class RPNExpression {
public:
  void push(TokenBase *t);
  TokenBase* pop();
  bool empty() const;
private:
  std::vector< TokenBase* > stack_;
};


class ShuntingYard {
public:
  ShuntingYard (const std::string& infix,
      std::map<std::string, double>* vars = 0);
  RPNExpression to_rpn();
private:
  const std::string expr_;
  std::map<std::string, double>* vars_;
  RPNExpression rpn_;
  std::stack< std::string > op_stack_;
  mutable std::map< std::string, int > op_precedence_;

  int precedence (std::string op) const;
  int stack_precedence() const;
  RPNExpression convert(const std::string &infix);
};

class calculator {
public:
  static double calculate(const std::string& expr,
      std::map<std::string, double>* vars = 0);
private:
  static void consume(std::string op, std::stack<double>* operands);
};

#endif // _SHUNTING_YARD_H
