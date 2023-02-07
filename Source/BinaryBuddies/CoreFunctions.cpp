// Fill out your copyright notice in the Description page of Project Settings.
#include "CoreFunctions.h"

int UCoreFunctions::Suma(int numar1, int numar2)
{
	return numar1+numar2;
}

int UCoreFunctions::Scadere(int numar1, int numar2)
{
	return numar1-numar2;
}

int UCoreFunctions::IfNeg(int numar)
{
	if (numar < 0)
		return 1;
	return 0;
}

int UCoreFunctions::IfZero(int numar)
{
	if (numar == 0)
		return 1;
	return 0;
}

int UCoreFunctions::Increment(int numar)
{
	return ++numar;
}

int UCoreFunctions::Decrement(int numar)
{
	return --numar;
}
