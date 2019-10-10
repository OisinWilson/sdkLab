#pragma once
/// <summary>
/// @Author : Oisin Wilson
/// </summary>

class Animation
{
private:
	class State* m_current; // note order of m_current is 
							// prior to setCurrent
	class State* m_previous;
public:
	Animation();
	~Animation();
	void setCurrent(State* s);
	void setPrevious(State* s);
	State* getCurrent();
	State* getPrevious();

	void idle();
	void jumping();
	void walking();
};

