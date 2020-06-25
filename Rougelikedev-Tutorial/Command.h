#pragma once
class Entity;

class Command
{
public:
	virtual ~Command() = default;
	void ActOn(Entity* entity) { entity_ = entity; }

	virtual bool Allowed(wchar_t key) = 0;
	virtual void Execute(wchar_t key) = 0;

protected:
	Entity* entity_ = nullptr;
};
