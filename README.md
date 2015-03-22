This is my pulse clock cleaner circuit for sequencing my live setup when
using Caustic 3 as a dum machine / master clock unit.

The analog pulse out from Caustic wasn't reliable enough for use
in live situations so I used an inverting buffer together with 
dual schmitt trigger inverters to clean the pulse and then an 
Arduino for generating a timing pulse with the exact length.

