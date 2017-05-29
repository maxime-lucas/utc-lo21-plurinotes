#include "Notes.h"

Note::~Note(){}

Version* Note::creerVersion(unsigned int i) {
	return new Version(this, i);	
}

Version::Version(Note* n, unsigned int i) : num(i) {
	if( typeid(*n) == typeid(Article) ) {
		this->note = new Article( dynamic_cast<Article&>(*n) );
	}
}

void Article::restaurerVersion(Version *v) {
	if( typeid(*this) == typeid(*(v->getNote()) ) ) {
		Article *a = dynamic_cast<Article*>(v->getNote());
		texte = a->getTexte();
		titre = a->getTitre();
	}
}

void Tache::restaurerVersion(Version *v) {
	if( typeid(*this) == typeid(*(v->getNote()) ) ) {
		Tache *t = dynamic_cast<Tache*>(v->getNote());
		titre = t->getTitre();
		action = t->getAction();
		priorite = t->getPriorite();
	}
}
