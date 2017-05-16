#include <string>
#include <iostream>
#include <typeinfo>

class Version;

class Note {

	protected:
	std::string identificateur;
	std::string titre;
	
	public:
	Note(const std::string &i, const std::string &t) : identificateur(i), titre(t) {}
	virtual ~Note() = 0;

	const std::string& getIdentificateur() const { return identificateur; }
	void setIdentificateur(const std::string& i) { identificateur = i; }
	const std::string& getTitre() const { return titre; }
	void setTitre(const std::string& t) { titre = t; }
	
	void afficher(std::ostream& f = std::cout) { 
		f << identificateur << " " << titre; 
	}

	Version *creerVersion(unsigned int);
	virtual void restaurerVersion(Version*) = 0;
};

class Article : public Note {
	
	protected:
	std::string texte;

	public:
	Article(const std::string &i, const std::string &t, const std::string &tx) : Note(i,t), texte(tx) {}

	const std::string& getTexte() const { return texte; }
	void setTexte(const std::string& tx) { texte = tx; }
	void restaurerVersion(Version*);
};

class Tache : public Note {
	
	protected:
	std::string action;
	unsigned int priorite;

	public:
	Tache(const std::string &i, const std::string &t, const std::string &a, unsigned int p) : Note(i,t), action(a), priorite(p) {}

	const std::string& getAction() const { return action; }
	unsigned int getPriorite() const { return priorite; }
	void setAction(const std::string &a) { action = a; }
	void setPriorite(unsigned int p) { priorite = p; }
	
	void restaurerVersion(Version*);
};

class Version {
	private:
	Note *note;
	unsigned int num;

	public:
	Version(Note* n,unsigned int i);
	unsigned int getNum() const { return num; }
	Note* getNote() const { return note; }
};


