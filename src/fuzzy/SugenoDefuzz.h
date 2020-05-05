//
// Created by balanche on 1/29/20.
//

#ifndef PROJETFLOU_SUGENODEFUZZ_H
#define PROJETFLOU_SUGENODEFUZZ_H

#include <vector>
#include "../core/NaryExpression.h"
#include "../core/BinaryExpression.h"
#include "../core/BinaryExpressionModel.h"
#include "../core/BinaryShadowExpression.h"
#include "SugenoThen.h"

namespace fuzzy{
    template <class T>
    class SugenoDefuzz : public core::NaryExpression<T>{

        public:
            SugenoDefuzz(){};
            virtual ~SugenoDefuzz(){};
            virtual T evaluate(const std::vector<core::Expression<T>*>*)const ;
        private:
    };

    template <class T>
    T SugenoDefuzz<T>::evaluate(const std::vector< core::Expression<T>*>*operandes)const{
        typename std::vector<core::Expression<T>*>::const_iterator it = operandes->begin();
        T numerateur = 0;
        T denumerateur = 0;

        for (; it != operandes->end(); it++){
            auto* bem = (core::BinaryExpressionModel<T>*)(*it);
            auto* bse = (core::BinaryShadowExpression<T>*)bem->getOperateur();
            auto* sugthen = (SugenoThen<T>*)bse->getTarget();
            numerateur+=bem->evaluate();
            denumerateur+=sugthen->getPremisse();
        }

        if(denumerateur==0){ //Division par 0 impossible.
            return 0;
        }
        else
            T tmp = numerateur/denumerateur;
            return numerateur/denumerateur;
    }



}


#endif //PROJETFLOU_SUGENODEFUZZ_H
