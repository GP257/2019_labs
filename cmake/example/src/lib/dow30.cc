#include "dow30.h"
#include <cstdlib> 
#include <ctime> 
#include <iostream>

dow30::dow30() {
  _companies = {"MMM 3M", "AXP American Express", "AAPL Apple", "BA Boeing",
    "CAT Caterpillar", "CVX Chevron", "CSCO Cisco", "KO Coca-Cola",
    "DIS Disney", "DWDP DowDuPont Inc", "XOM Exxon Mobil", "GS Goldman Sachs",
    "HD Home Depot", "IBM IBM", "INTC Intel", "JNJ Johnson & Johnson",
    "JPM JPMorgan Chase", "MCD McDonald's", "MRK Merck", "MSFT Microsoft",
    "NKE Nike", "PFE Pfizer", "PG Procter & Gamble", "TRV Travelers Companies Inc",
    "UTX United Technologies", "UNH UnitedHealth", "VZ Verizon", "V Visa",
    "WMT Wal-Mart", "WBA Walgreen"}; 
  srand((unsigned)time(0));
}

std::string dow30::randCompany() {
  return _companies[(rand()%30)]; 
}
