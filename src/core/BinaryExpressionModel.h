//
// Created by pisel on 28/01/2020.
//

#ifndef BINARYEXPRESSIONMODEL_H
#define BINARYEXPRESSIONMODEL_H

#include "Expression.h"
#include "BinaryExpression.h"

namespace core{
    template <class T>
    class BinaryExpressionModel: public Expression<T>, public BinaryExpression<T>{
    private:
        Expression<T>* left;
        Expression<T>* right;
        BinaryExpression<T>* ope;



    public:
        BinaryExpressionModel( Expression<T>* left, Expression<T>* right, BinaryExpression<T>* ope);

        virtual ~BinaryExpressionModel();
        virtual BinaryExpression<T>* getOperateur();
        virtual T evaluate()const;
        virtual T evaluate(const Expression<T>* l,const Expression<T>* r)const;
    };

    template<class T>
    T BinaryExpressionModel<T>::evaluate() const{
        if (left != nullptr && right != nullptr)
            return evaluate(left, right);
    }

    template<class T>
    BinaryExpressionModel<T>::BinaryExpressionModel(Expression<T>* left,Expression<T>* right, BinaryExpression<T>* ope):left(left), right(right),ope(ope) {}

    template<class T>
    BinaryExpressionModel<T>::~BinaryExpressionModel() {
    }

    template<class T>
    T BinaryExpressionModel<T>::evaluate(const Expression<T>* l, const Expression<T>* r) const {
        if (ope != nullptr)
            return ope->evaluate(l, r);
    }

    template<class T>
    BinaryExpression<T> *BinaryExpressionModel<T>::getOperateur() {
        return this->ope;
    }

}

#endif //BINARYEXPRESSIONMODEL_H
