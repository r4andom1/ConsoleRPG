#include "CharacterCreator.h"


CharacterCreator::CharacterCreator(const string& name, string playerClass)
	: m_name(name)
	, m_class(playerClass)
{
}

CharacterCreator::~CharacterCreator()
{
}

void CharacterCreator::start()
{
}

string CharacterCreator::toString() const
{
	return "\nName: " + m_name + "\nClass: " + m_class;
}
