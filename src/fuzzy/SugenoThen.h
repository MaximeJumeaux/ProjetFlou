//
// Created by pisel on 29/01/2020.
//

#ifndef SUGENOTHEN_H
#define SUGENOTHEN_H


#include "../core/BinaryExpression.h"
#include "Then.h"
#include "../core/Expression.h"

namespace fuzzy{
    template <class T>
    class SugenoThen : public Then<T> {
    public:
        virtual T evaluate(const core::Expression<T>* l,const core::Expression<T>* r)const ;
        virtual T getPremisse()const;
        virtual void setPremisse(T);
    private:
        mutable T valeurPremisse; // mutable car modification dans le const.
    };

    template<class T>
    T SugenoThen<T>::evaluate(const core::Expression<T>* l,const core::Expression<T>* r) const{
        if(l==nullptr||r== nullptr){
            //pblm TODO exception ou un truc du genre
            std::cout << "PROBLEME " << std::endl;
        }
        this->valeurPremisse = l->evaluate();

        return this->valeurPremisse*r->evaluate();
    }

    template<class T>
    T SugenoThen<T>::getPremisse() const {
        return this->valeurPremisse;
    }

    template<class T>
    void SugenoThen<T>::setPremisse(T premisse) {
        this->valeurPremisse = premisse;
    }


}


#endif //SUGENOTHEN_H
