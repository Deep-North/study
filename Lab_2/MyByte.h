#pragma once
#include "Bin.h"
#include "Oct.h"
#include "Hex.h"
#include <iostream>

union MyByte
{
private:
	Bin m_bin;
	Oct m_oct;
	Hex m_hex;
	unsigned char m_dec;

public:
	MyByte(unsigned char byte) { m_dec = byte; } //конструктор
	
	void ShowBin() { m_bin.Show(); }
	void ShowOct() { m_oct.Show(); }
	void ShowHex() { m_hex.Show(); }
	
	void ShowDec()
	{
		unsigned int d = m_dec;
		std::cout << "¬ывод в дес€тичном формате: " << d << std::endl;
	}

	void ShowBinPos(int pos) { m_bin.ShowPos(pos); }
	void ShowOctPos(int pos) { m_oct.ShowPos(pos); }
	void ShowHexnPos(int pos) { m_hex.ShowPos(pos); }
	
	void EditBin(int pos, int val) { m_bin.Edit(pos, val); }
	void EditOct(int pos, int val) { m_oct.Edit(pos, val); }
	void EditHex(int pos, int val) { m_hex.Edit(pos, val); }
};