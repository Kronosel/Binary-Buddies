// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"

#include "CoreFunctions.generated.h"

/**
 * 
 */
UCLASS()
class BINARYBUDDIES_API UCoreFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
private:
	UFUNCTION(BlueprintCallable, Category = "Core Functions", meta=(ToolTip="Suma a doua numere"))
		static int Suma(int numar1, int numar2);

	UFUNCTION(BlueprintCallable, Category = "Core Functions",meta=(ToolTip="Scaderea a doua numere"))
		static int Scadere(int numar1, int numar2);

	UFUNCTION(BlueprintCallable, Category = "Core Functions",meta=(ToolTip="Returneaza 1 daca numarul e negativ altfel returneaza 0"))
		static int IfNeg(int numar);

	UFUNCTION(BlueprintCallable, Category = "Core Functions", meta=(ToolTip = "Returneaza 1 daca numarul e zero altfel returneaza 0"))
		static int IfZero(int numar);

	UFUNCTION(BlueprintCallable, Category = "Core Functions", meta=(ToolTip = "Incrementeaza numarul cu 1"))
		static int Increment(int numar);

	UFUNCTION(BlueprintCallable, Category = "Core Functions", meta=(ToolTip = "Decrementeaza numarul cu 1"))
		static int Decrement(int numar);

	UFUNCTION(BlueprintCallable, Category = "File I/O")
		static FString LoadFileToString(FString filename);

	UFUNCTION(BlueprintCallable, Category = "File I/O")
		static TArray<FString> LoadFileToStringArray(FString filename);
};
