void TAVLCom::CopiarAVL(const TAVLCom &arbol) {
	if (!arbol.EsVacio()) {
		this->raiz = new TNodoAVL();
		this->raiz->item = arbol.raiz->item;
		this->raiz->iz.CopiarAVL(arbol.raiz->iz);
		this->raiz->de.CopiarAVL(arbol.raiz->de);
	} else{
		this->raiz = NULL;
	}
}

// Constructor de copia
TAVLCom::TAVLCom(const TAVLCom &t) {
	this->CopiarAVL(t);
}




// Sobrecarga del operador asignación
TAVLCom & TAVLCom::operator=(const TAVLCom & t) {
	if(this!= &t){
		(*this).~TAVLCom();//si son distintos se copian
		CopiarAVL(t);
	}
	return *this;
}

// Sobrecarga del operador igualdad
bool TAVLCom::operator==(const TAVLCom & arbol) const {

	if(this->raiz==NULL && arbol.raiz==NULL)//Si alguno de lso dos es null, es true
		return true;//si los dos son nulos true
	else{//sino, si...
		if((this->raiz==NULL && arbol.raiz!=NULL)||(this->raiz!=NULL&&arbol.raiz==NULL))//Si uno es nulo y el otro no, es false
			return false;//devuelvo false
		else{
			if((this->raiz->item == arbol.raiz->item) && (this->raiz->fe == arbol.raiz->fe)){//si el primer nodo es igual y el factorequilibrio tambien
				if((this->raiz->iz == arbol.raiz->iz) && (this->raiz->de == arbol.raiz->de))//si las dos raices son iguales true
					return true;//devuelvo true
				else
					return false;//si no,devuelvo false
			}
			else//si el primer nodo no es igual o el factor equilibrio es distinto false
				return false;
		}
	}
	return false;
}