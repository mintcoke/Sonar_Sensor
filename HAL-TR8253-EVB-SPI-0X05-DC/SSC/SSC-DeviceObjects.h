/*
* This source file is part of the EtherCAT Slave Stack Code licensed by Beckhoff Automation GmbH & Co KG, 33415 Verl, Germany.
* The corresponding license agreement applies. This hint shall not be removed.
*/

/**
* \addtogroup SSC-Device SSC-Device
* @{
*/

/**
\file SSC-DeviceObjects
\author ET9300Utilities.ApplicationHandler (Version 1.6.3.0) | EthercatSSC@beckhoff.com

\brief SSC-Device specific objects<br>
\brief NOTE : This file will be overwritten if a new object dictionary is generated!<br>
*/

#if defined(_SSC_DEVICE_) && (_SSC_DEVICE_ == 1)
#define PROTO
#else
#define PROTO extern
#endif
/******************************************************************************
*                    Object 0x1600 : DO Unit2
******************************************************************************/
/**
* \addtogroup 0x1600 0x1600 | DO Unit2
* @{
* \brief Object 0x1600 (DO Unit2) definition
*/
#ifdef _OBJD_
/**
* \brief Object entry descriptions<br>
* <br>
* SubIndex 0<br>
* SubIndex 1<br>
* SubIndex 2<br>
* SubIndex 3<br>
* SubIndex 4<br>
* SubIndex 5<br>
* SubIndex 6<br>
* SubIndex 7<br>
* SubIndex 8<br>
* SubIndex 9<br>
* SubIndex 10<br>
* SubIndex 11<br>
* SubIndex 12<br>
* SubIndex 13<br>
* SubIndex 14<br>
* SubIndex 15<br>
* SubIndex 16<br>
* SubIndex 17<br>
* SubIndex 18<br>
* SubIndex 19<br>
* SubIndex 20<br>
* SubIndex 21<br>
* SubIndex 22<br>
* SubIndex 23<br>
* SubIndex 24<br>
* SubIndex 25<br>
* SubIndex 26<br>
* SubIndex 27<br>
* SubIndex 28<br>
* SubIndex 29<br>
* SubIndex 30<br>
* SubIndex 31<br>
* SubIndex 32<br>
* SubIndex 33<br>
* SubIndex 34<br>
* SubIndex 35<br>
* SubIndex 36<br>
* SubIndex 37<br>
* SubIndex 38<br>
* SubIndex 39<br>
* SubIndex 40<br>
* SubIndex 41<br>
* SubIndex 42<br>
* SubIndex 43<br>
* SubIndex 44<br>
* SubIndex 45<br>
* SubIndex 46<br>
* SubIndex 47<br>
* SubIndex 48<br>
* SubIndex 49<br>
* SubIndex 50<br>
* SubIndex 51<br>
* SubIndex 52<br>
* SubIndex 53<br>
* SubIndex 54<br>
* SubIndex 55<br>
* SubIndex 56<br>
* SubIndex 57<br>
* SubIndex 58<br>
* SubIndex 59<br>
* SubIndex 60<br>
* SubIndex 61<br>
* SubIndex 62<br>
* SubIndex 63<br>
* SubIndex 64<br>
* SubIndex 65<br>
* SubIndex 66<br>
* SubIndex 67<br>
* SubIndex 68<br>
* SubIndex 69<br>
* SubIndex 70<br>
* SubIndex 71<br>
* SubIndex 72<br>
* SubIndex 73<br>
* SubIndex 74<br>
* SubIndex 75<br>
* SubIndex 76<br>
* SubIndex 77<br>
* SubIndex 78<br>
* SubIndex 79<br>
* SubIndex 80<br>
* SubIndex 81<br>
* SubIndex 82<br>
* SubIndex 83<br>
* SubIndex 84<br>
* SubIndex 85<br>
* SubIndex 86<br>
* SubIndex 87<br>
* SubIndex 88<br>
* SubIndex 89<br>
* SubIndex 90<br>
* SubIndex 91<br>
* SubIndex 92<br>
* SubIndex 93<br>
* SubIndex 94<br>
* SubIndex 95<br>
* SubIndex 96<br>
* SubIndex 97<br>
* SubIndex 98<br>
* SubIndex 99<br>
* SubIndex 100<br>
* SubIndex 101<br>
* SubIndex 102<br>
* SubIndex 103<br>
* SubIndex 104<br>
* SubIndex 105<br>
* SubIndex 106<br>
* SubIndex 107<br>
* SubIndex 108<br>
* SubIndex 109<br>
* SubIndex 110<br>
* SubIndex 111<br>
* SubIndex 112<br>
* SubIndex 113<br>
* SubIndex 114<br>
* SubIndex 115<br>
* SubIndex 116<br>
* SubIndex 117<br>
* SubIndex 118<br>
* SubIndex 119<br>
* SubIndex 120<br>
* SubIndex 121<br>
* SubIndex 122<br>
* SubIndex 123<br>
* SubIndex 124<br>
* SubIndex 125<br>
* SubIndex 126<br>
* SubIndex 127<br>
* SubIndex 128<br>
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0x1600[] = {
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ },
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex1 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex2 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex3 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex4 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex5 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex6 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex7 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex8 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex9 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex10 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex11 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex12 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex13 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex14 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex15 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex16 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex17 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex18 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex19 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex20 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex21 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex22 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex23 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex24 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex25 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex26 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex27 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex28 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex29 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex30 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex31 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex32 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex33 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex34 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex35 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex36 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex37 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex38 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex39 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex40 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex41 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex42 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex43 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex44 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex45 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex46 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex47 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex48 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex49 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex50 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex51 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex52 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex53 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex54 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex55 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex56 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex57 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex58 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex59 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex60 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex61 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex62 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex63 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex64 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex65 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex66 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex67 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex68 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex69 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex70 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex71 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex72 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex73 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex74 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex75 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex76 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex77 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex78 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex79 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex80 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex81 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex82 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex83 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex84 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex85 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex86 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex87 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex88 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex89 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex90 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex91 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex92 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex93 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex94 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex95 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex96 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex97 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex98 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex99 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex100 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex101 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex102 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex103 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex104 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex105 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex106 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex107 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex108 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex109 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex110 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex111 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex112 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex113 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex114 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex115 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex116 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex117 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex118 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex119 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex120 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex121 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex122 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex123 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex124 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex125 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex126 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex127 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }}; /* Subindex128 */

/**
* \brief Object/Entry names
*/
OBJCONST UCHAR OBJMEM aName0x1600[] = "DO Unit2\000"
"SubIndex 001\000"
"SubIndex 002\000"
"SubIndex 003\000"
"SubIndex 004\000"
"SubIndex 005\000"
"SubIndex 006\000"
"SubIndex 007\000"
"SubIndex 008\000"
"SubIndex 009\000"
"SubIndex 010\000"
"SubIndex 011\000"
"SubIndex 012\000"
"SubIndex 013\000"
"SubIndex 014\000"
"SubIndex 015\000"
"SubIndex 016\000"
"SubIndex 017\000"
"SubIndex 018\000"
"SubIndex 019\000"
"SubIndex 020\000"
"SubIndex 021\000"
"SubIndex 022\000"
"SubIndex 023\000"
"SubIndex 024\000"
"SubIndex 025\000"
"SubIndex 026\000"
"SubIndex 027\000"
"SubIndex 028\000"
"SubIndex 029\000"
"SubIndex 030\000"
"SubIndex 031\000"
"SubIndex 032\000"
"SubIndex 033\000"
"SubIndex 034\000"
"SubIndex 035\000"
"SubIndex 036\000"
"SubIndex 037\000"
"SubIndex 038\000"
"SubIndex 039\000"
"SubIndex 040\000"
"SubIndex 041\000"
"SubIndex 042\000"
"SubIndex 043\000"
"SubIndex 044\000"
"SubIndex 045\000"
"SubIndex 046\000"
"SubIndex 047\000"
"SubIndex 048\000"
"SubIndex 049\000"
"SubIndex 050\000"
"SubIndex 051\000"
"SubIndex 052\000"
"SubIndex 053\000"
"SubIndex 054\000"
"SubIndex 055\000"
"SubIndex 056\000"
"SubIndex 057\000"
"SubIndex 058\000"
"SubIndex 059\000"
"SubIndex 060\000"
"SubIndex 061\000"
"SubIndex 062\000"
"SubIndex 063\000"
"SubIndex 064\000"
"SubIndex 065\000"
"SubIndex 066\000"
"SubIndex 067\000"
"SubIndex 068\000"
"SubIndex 069\000"
"SubIndex 070\000"
"SubIndex 071\000"
"SubIndex 072\000"
"SubIndex 073\000"
"SubIndex 074\000"
"SubIndex 075\000"
"SubIndex 076\000"
"SubIndex 077\000"
"SubIndex 078\000"
"SubIndex 079\000"
"SubIndex 080\000"
"SubIndex 081\000"
"SubIndex 082\000"
"SubIndex 083\000"
"SubIndex 084\000"
"SubIndex 085\000"
"SubIndex 086\000"
"SubIndex 087\000"
"SubIndex 088\000"
"SubIndex 089\000"
"SubIndex 090\000"
"SubIndex 091\000"
"SubIndex 092\000"
"SubIndex 093\000"
"SubIndex 094\000"
"SubIndex 095\000"
"SubIndex 096\000"
"SubIndex 097\000"
"SubIndex 098\000"
"SubIndex 099\000"
"SubIndex 100\000"
"SubIndex 101\000"
"SubIndex 102\000"
"SubIndex 103\000"
"SubIndex 104\000"
"SubIndex 105\000"
"SubIndex 106\000"
"SubIndex 107\000"
"SubIndex 108\000"
"SubIndex 109\000"
"SubIndex 110\000"
"SubIndex 111\000"
"SubIndex 112\000"
"SubIndex 113\000"
"SubIndex 114\000"
"SubIndex 115\000"
"SubIndex 116\000"
"SubIndex 117\000"
"SubIndex 118\000"
"SubIndex 119\000"
"SubIndex 120\000"
"SubIndex 121\000"
"SubIndex 122\000"
"SubIndex 123\000"
"SubIndex 124\000"
"SubIndex 125\000"
"SubIndex 126\000"
"SubIndex 127\000"
"SubIndex 128\000\377";
#endif //#ifdef _OBJD_

#ifndef _SSC_DEVICE_OBJECTS_H_
/**
* \brief Object structure
*/
typedef struct OBJ_STRUCT_PACKED_START {
UINT16 u16SubIndex0;
UINT32 SI1; /* Subindex1 -  */
UINT32 SI2; /* Subindex2 -  */
UINT32 SI3; /* Subindex3 -  */
UINT32 SI4; /* Subindex4 -  */
UINT32 SI5; /* Subindex5 -  */
UINT32 SI6; /* Subindex6 -  */
UINT32 SI7; /* Subindex7 -  */
UINT32 SI8; /* Subindex8 -  */
UINT32 SI9; /* Subindex9 -  */
UINT32 SI10; /* Subindex10 -  */
UINT32 SI11; /* Subindex11 -  */
UINT32 SI12; /* Subindex12 -  */
UINT32 SI13; /* Subindex13 -  */
UINT32 SI14; /* Subindex14 -  */
UINT32 SI15; /* Subindex15 -  */
UINT32 SI16; /* Subindex16 -  */
UINT32 SI17; /* Subindex17 -  */
UINT32 SI18; /* Subindex18 -  */
UINT32 SI19; /* Subindex19 -  */
UINT32 SI20; /* Subindex20 -  */
UINT32 SI21; /* Subindex21 -  */
UINT32 SI22; /* Subindex22 -  */
UINT32 SI23; /* Subindex23 -  */
UINT32 SI24; /* Subindex24 -  */
UINT32 SI25; /* Subindex25 -  */
UINT32 SI26; /* Subindex26 -  */
UINT32 SI27; /* Subindex27 -  */
UINT32 SI28; /* Subindex28 -  */
UINT32 SI29; /* Subindex29 -  */
UINT32 SI30; /* Subindex30 -  */
UINT32 SI31; /* Subindex31 -  */
UINT32 SI32; /* Subindex32 -  */
UINT32 SI33; /* Subindex33 -  */
UINT32 SI34; /* Subindex34 -  */
UINT32 SI35; /* Subindex35 -  */
UINT32 SI36; /* Subindex36 -  */
UINT32 SI37; /* Subindex37 -  */
UINT32 SI38; /* Subindex38 -  */
UINT32 SI39; /* Subindex39 -  */
UINT32 SI40; /* Subindex40 -  */
UINT32 SI41; /* Subindex41 -  */
UINT32 SI42; /* Subindex42 -  */
UINT32 SI43; /* Subindex43 -  */
UINT32 SI44; /* Subindex44 -  */
UINT32 SI45; /* Subindex45 -  */
UINT32 SI46; /* Subindex46 -  */
UINT32 SI47; /* Subindex47 -  */
UINT32 SI48; /* Subindex48 -  */
UINT32 SI49; /* Subindex49 -  */
UINT32 SI50; /* Subindex50 -  */
UINT32 SI51; /* Subindex51 -  */
UINT32 SI52; /* Subindex52 -  */
UINT32 SI53; /* Subindex53 -  */
UINT32 SI54; /* Subindex54 -  */
UINT32 SI55; /* Subindex55 -  */
UINT32 SI56; /* Subindex56 -  */
UINT32 SI57; /* Subindex57 -  */
UINT32 SI58; /* Subindex58 -  */
UINT32 SI59; /* Subindex59 -  */
UINT32 SI60; /* Subindex60 -  */
UINT32 SI61; /* Subindex61 -  */
UINT32 SI62; /* Subindex62 -  */
UINT32 SI63; /* Subindex63 -  */
UINT32 SI64; /* Subindex64 -  */
UINT32 SI65; /* Subindex65 -  */
UINT32 SI66; /* Subindex66 -  */
UINT32 SI67; /* Subindex67 -  */
UINT32 SI68; /* Subindex68 -  */
UINT32 SI69; /* Subindex69 -  */
UINT32 SI70; /* Subindex70 -  */
UINT32 SI71; /* Subindex71 -  */
UINT32 SI72; /* Subindex72 -  */
UINT32 SI73; /* Subindex73 -  */
UINT32 SI74; /* Subindex74 -  */
UINT32 SI75; /* Subindex75 -  */
UINT32 SI76; /* Subindex76 -  */
UINT32 SI77; /* Subindex77 -  */
UINT32 SI78; /* Subindex78 -  */
UINT32 SI79; /* Subindex79 -  */
UINT32 SI80; /* Subindex80 -  */
UINT32 SI81; /* Subindex81 -  */
UINT32 SI82; /* Subindex82 -  */
UINT32 SI83; /* Subindex83 -  */
UINT32 SI84; /* Subindex84 -  */
UINT32 SI85; /* Subindex85 -  */
UINT32 SI86; /* Subindex86 -  */
UINT32 SI87; /* Subindex87 -  */
UINT32 SI88; /* Subindex88 -  */
UINT32 SI89; /* Subindex89 -  */
UINT32 SI90; /* Subindex90 -  */
UINT32 SI91; /* Subindex91 -  */
UINT32 SI92; /* Subindex92 -  */
UINT32 SI93; /* Subindex93 -  */
UINT32 SI94; /* Subindex94 -  */
UINT32 SI95; /* Subindex95 -  */
UINT32 SI96; /* Subindex96 -  */
UINT32 SI97; /* Subindex97 -  */
UINT32 SI98; /* Subindex98 -  */
UINT32 SI99; /* Subindex99 -  */
UINT32 SI100; /* Subindex100 -  */
UINT32 SI101; /* Subindex101 -  */
UINT32 SI102; /* Subindex102 -  */
UINT32 SI103; /* Subindex103 -  */
UINT32 SI104; /* Subindex104 -  */
UINT32 SI105; /* Subindex105 -  */
UINT32 SI106; /* Subindex106 -  */
UINT32 SI107; /* Subindex107 -  */
UINT32 SI108; /* Subindex108 -  */
UINT32 SI109; /* Subindex109 -  */
UINT32 SI110; /* Subindex110 -  */
UINT32 SI111; /* Subindex111 -  */
UINT32 SI112; /* Subindex112 -  */
UINT32 SI113; /* Subindex113 -  */
UINT32 SI114; /* Subindex114 -  */
UINT32 SI115; /* Subindex115 -  */
UINT32 SI116; /* Subindex116 -  */
UINT32 SI117; /* Subindex117 -  */
UINT32 SI118; /* Subindex118 -  */
UINT32 SI119; /* Subindex119 -  */
UINT32 SI120; /* Subindex120 -  */
UINT32 SI121; /* Subindex121 -  */
UINT32 SI122; /* Subindex122 -  */
UINT32 SI123; /* Subindex123 -  */
UINT32 SI124; /* Subindex124 -  */
UINT32 SI125; /* Subindex125 -  */
UINT32 SI126; /* Subindex126 -  */
UINT32 SI127; /* Subindex127 -  */
UINT32 SI128; /* Subindex128 -  */
} OBJ_STRUCT_PACKED_END
TOBJ1600;
#endif //#ifndef _SSC_DEVICE_OBJECTS_H_

/**
* \brief Object variable
*/
PROTO TOBJ1600 DOUnit20x1600
#if defined(_SSC_DEVICE_) && (_SSC_DEVICE_ == 1)
={128,0x70000110,0x70000210,0x70000310,0x70000410,0x70000510,0x70000610,0x70000710,0x70000810,0x70000910,0x70000A10,0x70000B10,0x70000C10,0x70000D10,0x70000E10,0x70000F10,0x70001010,0x70001110,0x70001210,0x70001310,0x70001410,0x70001510,0x70001610,0x70001710,0x70001810,0x70001910,0x70001A10,0x70001B10,0x70001C10,0x70001D10,0x70001E10,0x70001F10,0x70002010,0x70002110,0x70002210,0x70002310,0x70002410,0x70002510,0x70002610,0x70002710,0x70002810,0x70002910,0x70002A10,0x70002B10,0x70002C10,0x70002D10,0x70002E10,0x70002F10,0x70003010,0x70003110,0x70003210,0x70003310,0x70003410,0x70003510,0x70003610,0x70003710,0x70003810,0x70003910,0x70003A10,0x70003B10,0x70003C10,0x70003D10,0x70003E10,0x70003F10,0x70004010,0x70004110,0x70004210,0x70004310,0x70004410,0x70004510,0x70004610,0x70004710,0x70004810,0x70004910,0x70004A10,0x70004B10,0x70004C10,0x70004D10,0x70004E10,0x70004F10,0x70005010,0x70005110,0x70005210,0x70005310,0x70005410,0x70005510,0x70005610,0x70005710,0x70005810,0x70005910,0x70005A10,0x70005B10,0x70005C10,0x70005D10,0x70005E10,0x70005F10,0x70006010,0x70006110,0x70006210,0x70006310,0x70006410,0x70006510,0x70006610,0x70006710,0x70006810,0x70006910,0x70006A10,0x70006B10,0x70006C10,0x70006D10,0x70006E10,0x70006F10,0x70007010,0x70007110,0x70007210,0x70007310,0x70007410,0x70007510,0x70007610,0x70007710,0x70007810,0x70007910,0x70007A10,0x70007B10,0x70007C10,0x70007D10,0x70007E10,0x70007F10,0x70008010}
#endif
;
/** @}*/



/******************************************************************************
*                    Object 0x1A00 : DI Unit1
******************************************************************************/
/**
* \addtogroup 0x1A00 0x1A00 | DI Unit1
* @{
* \brief Object 0x1A00 (DI Unit1) definition
*/
#ifdef _OBJD_
/**
* \brief Object entry descriptions<br>
* <br>
* SubIndex 0<br>
* SubIndex 1<br>
* SubIndex 2<br>
* SubIndex 3<br>
* SubIndex 4<br>
* SubIndex 5<br>
* SubIndex 6<br>
* SubIndex 7<br>
* SubIndex 8<br>
* SubIndex 9<br>
* SubIndex 10<br>
* SubIndex 11<br>
* SubIndex 12<br>
* SubIndex 13<br>
* SubIndex 14<br>
* SubIndex 15<br>
* SubIndex 16<br>
* SubIndex 17<br>
* SubIndex 18<br>
* SubIndex 19<br>
* SubIndex 20<br>
* SubIndex 21<br>
* SubIndex 22<br>
* SubIndex 23<br>
* SubIndex 24<br>
* SubIndex 25<br>
* SubIndex 26<br>
* SubIndex 27<br>
* SubIndex 28<br>
* SubIndex 29<br>
* SubIndex 30<br>
* SubIndex 31<br>
* SubIndex 32<br>
* SubIndex 33<br>
* SubIndex 34<br>
* SubIndex 35<br>
* SubIndex 36<br>
* SubIndex 37<br>
* SubIndex 38<br>
* SubIndex 39<br>
* SubIndex 40<br>
* SubIndex 41<br>
* SubIndex 42<br>
* SubIndex 43<br>
* SubIndex 44<br>
* SubIndex 45<br>
* SubIndex 46<br>
* SubIndex 47<br>
* SubIndex 48<br>
* SubIndex 49<br>
* SubIndex 50<br>
* SubIndex 51<br>
* SubIndex 52<br>
* SubIndex 53<br>
* SubIndex 54<br>
* SubIndex 55<br>
* SubIndex 56<br>
* SubIndex 57<br>
* SubIndex 58<br>
* SubIndex 59<br>
* SubIndex 60<br>
* SubIndex 61<br>
* SubIndex 62<br>
* SubIndex 63<br>
* SubIndex 64<br>
* SubIndex 65<br>
* SubIndex 66<br>
* SubIndex 67<br>
* SubIndex 68<br>
* SubIndex 69<br>
* SubIndex 70<br>
* SubIndex 71<br>
* SubIndex 72<br>
* SubIndex 73<br>
* SubIndex 74<br>
* SubIndex 75<br>
* SubIndex 76<br>
* SubIndex 77<br>
* SubIndex 78<br>
* SubIndex 79<br>
* SubIndex 80<br>
* SubIndex 81<br>
* SubIndex 82<br>
* SubIndex 83<br>
* SubIndex 84<br>
* SubIndex 85<br>
* SubIndex 86<br>
* SubIndex 87<br>
* SubIndex 88<br>
* SubIndex 89<br>
* SubIndex 90<br>
* SubIndex 91<br>
* SubIndex 92<br>
* SubIndex 93<br>
* SubIndex 94<br>
* SubIndex 95<br>
* SubIndex 96<br>
* SubIndex 97<br>
* SubIndex 98<br>
* SubIndex 99<br>
* SubIndex 100<br>
* SubIndex 101<br>
* SubIndex 102<br>
* SubIndex 103<br>
* SubIndex 104<br>
* SubIndex 105<br>
* SubIndex 106<br>
* SubIndex 107<br>
* SubIndex 108<br>
* SubIndex 109<br>
* SubIndex 110<br>
* SubIndex 111<br>
* SubIndex 112<br>
* SubIndex 113<br>
* SubIndex 114<br>
* SubIndex 115<br>
* SubIndex 116<br>
* SubIndex 117<br>
* SubIndex 118<br>
* SubIndex 119<br>
* SubIndex 120<br>
* SubIndex 121<br>
* SubIndex 122<br>
* SubIndex 123<br>
* SubIndex 124<br>
* SubIndex 125<br>
* SubIndex 126<br>
* SubIndex 127<br>
* SubIndex 128<br>
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0x1A00[] = {
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ },
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex1 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex2 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex3 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex4 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex5 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex6 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex7 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex8 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex9 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex10 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex11 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex12 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex13 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex14 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex15 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex16 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex17 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex18 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex19 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex20 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex21 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex22 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex23 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex24 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex25 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex26 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex27 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex28 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex29 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex30 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex31 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex32 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex33 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex34 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex35 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex36 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex37 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex38 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex39 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex40 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex41 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex42 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex43 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex44 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex45 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex46 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex47 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex48 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex49 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex50 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex51 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex52 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex53 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex54 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex55 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex56 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex57 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex58 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex59 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex60 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex61 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex62 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex63 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex64 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex65 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex66 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex67 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex68 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex69 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex70 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex71 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex72 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex73 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex74 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex75 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex76 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex77 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex78 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex79 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex80 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex81 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex82 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex83 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex84 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex85 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex86 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex87 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex88 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex89 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex90 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex91 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex92 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex93 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex94 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex95 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex96 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex97 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex98 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex99 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex100 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex101 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex102 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex103 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex104 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex105 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex106 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex107 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex108 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex109 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex110 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex111 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex112 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex113 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex114 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex115 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex116 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex117 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex118 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex119 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex120 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex121 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex122 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex123 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex124 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex125 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex126 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex127 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }}; /* Subindex128 */

/**
* \brief Object/Entry names
*/
OBJCONST UCHAR OBJMEM aName0x1A00[] = "DI Unit1\000"
"SubIndex 001\000"
"SubIndex 002\000"
"SubIndex 003\000"
"SubIndex 004\000"
"SubIndex 005\000"
"SubIndex 006\000"
"SubIndex 007\000"
"SubIndex 008\000"
"SubIndex 009\000"
"SubIndex 010\000"
"SubIndex 011\000"
"SubIndex 012\000"
"SubIndex 013\000"
"SubIndex 014\000"
"SubIndex 015\000"
"SubIndex 016\000"
"SubIndex 017\000"
"SubIndex 018\000"
"SubIndex 019\000"
"SubIndex 020\000"
"SubIndex 021\000"
"SubIndex 022\000"
"SubIndex 023\000"
"SubIndex 024\000"
"SubIndex 025\000"
"SubIndex 026\000"
"SubIndex 027\000"
"SubIndex 028\000"
"SubIndex 029\000"
"SubIndex 030\000"
"SubIndex 031\000"
"SubIndex 032\000"
"SubIndex 033\000"
"SubIndex 034\000"
"SubIndex 035\000"
"SubIndex 036\000"
"SubIndex 037\000"
"SubIndex 038\000"
"SubIndex 039\000"
"SubIndex 040\000"
"SubIndex 041\000"
"SubIndex 042\000"
"SubIndex 043\000"
"SubIndex 044\000"
"SubIndex 045\000"
"SubIndex 046\000"
"SubIndex 047\000"
"SubIndex 048\000"
"SubIndex 049\000"
"SubIndex 050\000"
"SubIndex 051\000"
"SubIndex 052\000"
"SubIndex 053\000"
"SubIndex 054\000"
"SubIndex 055\000"
"SubIndex 056\000"
"SubIndex 057\000"
"SubIndex 058\000"
"SubIndex 059\000"
"SubIndex 060\000"
"SubIndex 061\000"
"SubIndex 062\000"
"SubIndex 063\000"
"SubIndex 064\000"
"SubIndex 065\000"
"SubIndex 066\000"
"SubIndex 067\000"
"SubIndex 068\000"
"SubIndex 069\000"
"SubIndex 070\000"
"SubIndex 071\000"
"SubIndex 072\000"
"SubIndex 073\000"
"SubIndex 074\000"
"SubIndex 075\000"
"SubIndex 076\000"
"SubIndex 077\000"
"SubIndex 078\000"
"SubIndex 079\000"
"SubIndex 080\000"
"SubIndex 081\000"
"SubIndex 082\000"
"SubIndex 083\000"
"SubIndex 084\000"
"SubIndex 085\000"
"SubIndex 086\000"
"SubIndex 087\000"
"SubIndex 088\000"
"SubIndex 089\000"
"SubIndex 090\000"
"SubIndex 091\000"
"SubIndex 092\000"
"SubIndex 093\000"
"SubIndex 094\000"
"SubIndex 095\000"
"SubIndex 096\000"
"SubIndex 097\000"
"SubIndex 098\000"
"SubIndex 099\000"
"SubIndex 100\000"
"SubIndex 101\000"
"SubIndex 102\000"
"SubIndex 103\000"
"SubIndex 104\000"
"SubIndex 105\000"
"SubIndex 106\000"
"SubIndex 107\000"
"SubIndex 108\000"
"SubIndex 109\000"
"SubIndex 110\000"
"SubIndex 111\000"
"SubIndex 112\000"
"SubIndex 113\000"
"SubIndex 114\000"
"SubIndex 115\000"
"SubIndex 116\000"
"SubIndex 117\000"
"SubIndex 118\000"
"SubIndex 119\000"
"SubIndex 120\000"
"SubIndex 121\000"
"SubIndex 122\000"
"SubIndex 123\000"
"SubIndex 124\000"
"SubIndex 125\000"
"SubIndex 126\000"
"SubIndex 127\000"
"SubIndex 128\000\377";
#endif //#ifdef _OBJD_

#ifndef _SSC_DEVICE_OBJECTS_H_
/**
* \brief Object structure
*/
typedef struct OBJ_STRUCT_PACKED_START {
UINT16 u16SubIndex0;
UINT32 SI1; /* Subindex1 -  */
UINT32 SI2; /* Subindex2 -  */
UINT32 SI3; /* Subindex3 -  */
UINT32 SI4; /* Subindex4 -  */
UINT32 SI5; /* Subindex5 -  */
UINT32 SI6; /* Subindex6 -  */
UINT32 SI7; /* Subindex7 -  */
UINT32 SI8; /* Subindex8 -  */
UINT32 SI9; /* Subindex9 -  */
UINT32 SI10; /* Subindex10 -  */
UINT32 SI11; /* Subindex11 -  */
UINT32 SI12; /* Subindex12 -  */
UINT32 SI13; /* Subindex13 -  */
UINT32 SI14; /* Subindex14 -  */
UINT32 SI15; /* Subindex15 -  */
UINT32 SI16; /* Subindex16 -  */
UINT32 SI17; /* Subindex17 -  */
UINT32 SI18; /* Subindex18 -  */
UINT32 SI19; /* Subindex19 -  */
UINT32 SI20; /* Subindex20 -  */
UINT32 SI21; /* Subindex21 -  */
UINT32 SI22; /* Subindex22 -  */
UINT32 SI23; /* Subindex23 -  */
UINT32 SI24; /* Subindex24 -  */
UINT32 SI25; /* Subindex25 -  */
UINT32 SI26; /* Subindex26 -  */
UINT32 SI27; /* Subindex27 -  */
UINT32 SI28; /* Subindex28 -  */
UINT32 SI29; /* Subindex29 -  */
UINT32 SI30; /* Subindex30 -  */
UINT32 SI31; /* Subindex31 -  */
UINT32 SI32; /* Subindex32 -  */
UINT32 SI33; /* Subindex33 -  */
UINT32 SI34; /* Subindex34 -  */
UINT32 SI35; /* Subindex35 -  */
UINT32 SI36; /* Subindex36 -  */
UINT32 SI37; /* Subindex37 -  */
UINT32 SI38; /* Subindex38 -  */
UINT32 SI39; /* Subindex39 -  */
UINT32 SI40; /* Subindex40 -  */
UINT32 SI41; /* Subindex41 -  */
UINT32 SI42; /* Subindex42 -  */
UINT32 SI43; /* Subindex43 -  */
UINT32 SI44; /* Subindex44 -  */
UINT32 SI45; /* Subindex45 -  */
UINT32 SI46; /* Subindex46 -  */
UINT32 SI47; /* Subindex47 -  */
UINT32 SI48; /* Subindex48 -  */
UINT32 SI49; /* Subindex49 -  */
UINT32 SI50; /* Subindex50 -  */
UINT32 SI51; /* Subindex51 -  */
UINT32 SI52; /* Subindex52 -  */
UINT32 SI53; /* Subindex53 -  */
UINT32 SI54; /* Subindex54 -  */
UINT32 SI55; /* Subindex55 -  */
UINT32 SI56; /* Subindex56 -  */
UINT32 SI57; /* Subindex57 -  */
UINT32 SI58; /* Subindex58 -  */
UINT32 SI59; /* Subindex59 -  */
UINT32 SI60; /* Subindex60 -  */
UINT32 SI61; /* Subindex61 -  */
UINT32 SI62; /* Subindex62 -  */
UINT32 SI63; /* Subindex63 -  */
UINT32 SI64; /* Subindex64 -  */
UINT32 SI65; /* Subindex65 -  */
UINT32 SI66; /* Subindex66 -  */
UINT32 SI67; /* Subindex67 -  */
UINT32 SI68; /* Subindex68 -  */
UINT32 SI69; /* Subindex69 -  */
UINT32 SI70; /* Subindex70 -  */
UINT32 SI71; /* Subindex71 -  */
UINT32 SI72; /* Subindex72 -  */
UINT32 SI73; /* Subindex73 -  */
UINT32 SI74; /* Subindex74 -  */
UINT32 SI75; /* Subindex75 -  */
UINT32 SI76; /* Subindex76 -  */
UINT32 SI77; /* Subindex77 -  */
UINT32 SI78; /* Subindex78 -  */
UINT32 SI79; /* Subindex79 -  */
UINT32 SI80; /* Subindex80 -  */
UINT32 SI81; /* Subindex81 -  */
UINT32 SI82; /* Subindex82 -  */
UINT32 SI83; /* Subindex83 -  */
UINT32 SI84; /* Subindex84 -  */
UINT32 SI85; /* Subindex85 -  */
UINT32 SI86; /* Subindex86 -  */
UINT32 SI87; /* Subindex87 -  */
UINT32 SI88; /* Subindex88 -  */
UINT32 SI89; /* Subindex89 -  */
UINT32 SI90; /* Subindex90 -  */
UINT32 SI91; /* Subindex91 -  */
UINT32 SI92; /* Subindex92 -  */
UINT32 SI93; /* Subindex93 -  */
UINT32 SI94; /* Subindex94 -  */
UINT32 SI95; /* Subindex95 -  */
UINT32 SI96; /* Subindex96 -  */
UINT32 SI97; /* Subindex97 -  */
UINT32 SI98; /* Subindex98 -  */
UINT32 SI99; /* Subindex99 -  */
UINT32 SI100; /* Subindex100 -  */
UINT32 SI101; /* Subindex101 -  */
UINT32 SI102; /* Subindex102 -  */
UINT32 SI103; /* Subindex103 -  */
UINT32 SI104; /* Subindex104 -  */
UINT32 SI105; /* Subindex105 -  */
UINT32 SI106; /* Subindex106 -  */
UINT32 SI107; /* Subindex107 -  */
UINT32 SI108; /* Subindex108 -  */
UINT32 SI109; /* Subindex109 -  */
UINT32 SI110; /* Subindex110 -  */
UINT32 SI111; /* Subindex111 -  */
UINT32 SI112; /* Subindex112 -  */
UINT32 SI113; /* Subindex113 -  */
UINT32 SI114; /* Subindex114 -  */
UINT32 SI115; /* Subindex115 -  */
UINT32 SI116; /* Subindex116 -  */
UINT32 SI117; /* Subindex117 -  */
UINT32 SI118; /* Subindex118 -  */
UINT32 SI119; /* Subindex119 -  */
UINT32 SI120; /* Subindex120 -  */
UINT32 SI121; /* Subindex121 -  */
UINT32 SI122; /* Subindex122 -  */
UINT32 SI123; /* Subindex123 -  */
UINT32 SI124; /* Subindex124 -  */
UINT32 SI125; /* Subindex125 -  */
UINT32 SI126; /* Subindex126 -  */
UINT32 SI127; /* Subindex127 -  */
UINT32 SI128; /* Subindex128 -  */
} OBJ_STRUCT_PACKED_END
TOBJ1A00;
#endif //#ifndef _SSC_DEVICE_OBJECTS_H_

/**
* \brief Object variable
*/
PROTO TOBJ1A00 DIUnit10x1A00
#if defined(_SSC_DEVICE_) && (_SSC_DEVICE_ == 1)
={128,0x60000110,0x60000210,0x60000310,0x60000410,0x60000510,0x60000610,0x60000710,0x60000810,0x60000910,0x60000A10,0x60000B10,0x60000C10,0x60000D10,0x60000E10,0x60000F10,0x60001010,0x60001110,0x60001210,0x60001310,0x60001410,0x60001510,0x60001610,0x60001710,0x60001810,0x60001910,0x60001A10,0x60001B10,0x60001C10,0x60001D10,0x60001E10,0x60001F10,0x60002010,0x60002110,0x60002210,0x60002310,0x60002410,0x60002510,0x60002610,0x60002710,0x60002810,0x60002910,0x60002A10,0x60002B10,0x60002C10,0x60002D10,0x60002E10,0x60002F10,0x60003010,0x60003110,0x60003210,0x60003310,0x60003410,0x60003510,0x60003610,0x60003710,0x60003810,0x60003910,0x60003A10,0x60003B10,0x60003C10,0x60003D10,0x60003E10,0x60003F10,0x60004010,0x60004110,0x60004210,0x60004310,0x60004410,0x60004510,0x60004610,0x60004710,0x60004810,0x60004910,0x60004A10,0x60004B10,0x60004C10,0x60004D10,0x60004E10,0x60004F10,0x60005010,0x60005110,0x60005210,0x60005310,0x60005410,0x60005510,0x60005610,0x60005710,0x60005810,0x60005910,0x60005A10,0x60005B10,0x60005C10,0x60005D10,0x60005E10,0x60005F10,0x60006010,0x60006110,0x60006210,0x60006310,0x60006410,0x60006510,0x60006610,0x60006710,0x60006810,0x60006910,0x60006A10,0x60006B10,0x60006C10,0x60006D10,0x60006E10,0x60006F10,0x60007010,0x60007110,0x60007210,0x60007310,0x60007410,0x60007510,0x60007610,0x60007710,0x60007810,0x60007910,0x60007A10,0x60007B10,0x60007C10,0x60007D10,0x60007E10,0x60007F10,0x60008010}
#endif
;
/** @}*/



/******************************************************************************
*                    Object 0x1C12 : SyncManager 2 assignment
******************************************************************************/
/**
* \addtogroup 0x1C12 0x1C12 | SyncManager 2 assignment
* @{
* \brief Object 0x1C12 (SyncManager 2 assignment) definition
*/
#ifdef _OBJD_
/**
* \brief Entry descriptions<br>
* 
* Subindex 0<br>
* Subindex 1 - n (the same entry description is used)<br>
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0x1C12[] = {
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ },
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READ }};

/**
* \brief Object name definition<br>
* For Subindex 1 to n the syntax 'Subindex XXX' is used
*/
OBJCONST UCHAR OBJMEM aName0x1C12[] = "SyncManager 2 assignment\000\377";
#endif //#ifdef _OBJD_

#ifndef _SSC_DEVICE_OBJECTS_H_
/**
* \brief Object structure
*/
typedef struct OBJ_STRUCT_PACKED_START {
UINT16   u16SubIndex0;  /**< \brief Subindex 0 */
UINT16 aEntries[1];  /**< \brief Subindex 1 - 1 */
} OBJ_STRUCT_PACKED_END
TOBJ1C12;
#endif //#ifndef _SSC_DEVICE_OBJECTS_H_

/**
* \brief Object variable
*/
PROTO TOBJ1C12 sRxPDOassign
#if defined(_SSC_DEVICE_) && (_SSC_DEVICE_ == 1)
={1,{0x1600}}
#endif
;
/** @}*/



/******************************************************************************
*                    Object 0x1C13 : SyncManager 3 assignment
******************************************************************************/
/**
* \addtogroup 0x1C13 0x1C13 | SyncManager 3 assignment
* @{
* \brief Object 0x1C13 (SyncManager 3 assignment) definition
*/
#ifdef _OBJD_
/**
* \brief Entry descriptions<br>
* 
* Subindex 0<br>
* Subindex 1 - n (the same entry description is used)<br>
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0x1C13[] = {
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ },
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READ }};

/**
* \brief Object name definition<br>
* For Subindex 1 to n the syntax 'Subindex XXX' is used
*/
OBJCONST UCHAR OBJMEM aName0x1C13[] = "SyncManager 3 assignment\000\377";
#endif //#ifdef _OBJD_

#ifndef _SSC_DEVICE_OBJECTS_H_
/**
* \brief Object structure
*/
typedef struct OBJ_STRUCT_PACKED_START {
UINT16   u16SubIndex0;  /**< \brief Subindex 0 */
UINT16 aEntries[1];  /**< \brief Subindex 1 - 1 */
} OBJ_STRUCT_PACKED_END
TOBJ1C13;
#endif //#ifndef _SSC_DEVICE_OBJECTS_H_

/**
* \brief Object variable
*/
PROTO TOBJ1C13 sTxPDOassign
#if defined(_SSC_DEVICE_) && (_SSC_DEVICE_ == 1)
={1,{0x1A00}}
#endif
;
/** @}*/



/******************************************************************************
*                    Object 0x6000 : DI Unit1
******************************************************************************/
/**
* \addtogroup 0x6000 0x6000 | DI Unit1
* @{
* \brief Object 0x6000 (DI Unit1) definition
*/
#ifdef _OBJD_
/**
* \brief Entry descriptions<br>
* 
* Subindex 0<br>
* Subindex 1 - n (the same entry description is used)<br>
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0x6000[] = {
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ },
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READ }};

/**
* \brief Object name definition<br>
* For Subindex 1 to n the syntax 'Subindex XXX' is used
*/
OBJCONST UCHAR OBJMEM aName0x6000[] = "DI Unit1\000\377";
#endif //#ifdef _OBJD_

#ifndef _SSC_DEVICE_OBJECTS_H_
/**
* \brief Object structure
*/
typedef struct OBJ_STRUCT_PACKED_START {
UINT16   u16SubIndex0;  /**< \brief Subindex 0 */
UINT16 aEntries[128];  /**< \brief Subindex 1 - 128 */
} OBJ_STRUCT_PACKED_END
TOBJ6000;
#endif //#ifndef _SSC_DEVICE_OBJECTS_H_

/**
* \brief Object variable
*/
PROTO TOBJ6000 DIUnit10x6000
#if defined(_SSC_DEVICE_) && (_SSC_DEVICE_ == 1)
={128,{0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000}}
#endif
;
/** @}*/



/******************************************************************************
*                    Object 0x7000 : DO Unit2
******************************************************************************/
/**
* \addtogroup 0x7000 0x7000 | DO Unit2
* @{
* \brief Object 0x7000 (DO Unit2) definition
*/
#ifdef _OBJD_
/**
* \brief Entry descriptions<br>
* 
* Subindex 0<br>
* Subindex 1 - n (the same entry description is used)<br>
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0x7000[] = {
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ },
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READ }};

/**
* \brief Object name definition<br>
* For Subindex 1 to n the syntax 'Subindex XXX' is used
*/
OBJCONST UCHAR OBJMEM aName0x7000[] = "DO Unit2\000\377";
#endif //#ifdef _OBJD_

#ifndef _SSC_DEVICE_OBJECTS_H_
/**
* \brief Object structure
*/
typedef struct OBJ_STRUCT_PACKED_START {
UINT16   u16SubIndex0;  /**< \brief Subindex 0 */
UINT16 aEntries[128];  /**< \brief Subindex 1 - 128 */
} OBJ_STRUCT_PACKED_END
TOBJ7000;
#endif //#ifndef _SSC_DEVICE_OBJECTS_H_

/**
* \brief Object variable
*/
PROTO TOBJ7000 DOUnit20x7000
#if defined(_SSC_DEVICE_) && (_SSC_DEVICE_ == 1)
={128,{0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000}}
#endif
;
/** @}*/



/******************************************************************************
*                    Object 0xF008 : Parameters Handing
******************************************************************************/
/**
* \addtogroup 0xF008 0xF008 | Parameters Handing
* @{
* \brief Object 0xF008 (Parameters Handing) definition
*/
#ifdef _OBJD_
/**
* \brief Object entry descriptions<br>
* <br>
* SubIndex 0<br>
* SubIndex 1 - Save Current Parameters<br>
* SubIndex 2 - Restore Default Parameters<br>
* SubIndex 3 - Checksum<br>
* SubIndex 4 - Vendor Reserve<br>
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0xF008[] = {
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ },
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READWRITE }, /* Subindex1 - Save Current Parameters */
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READWRITE }, /* Subindex2 - Restore Default Parameters */
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READ }, /* Subindex3 - Checksum */
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READWRITE }}; /* Subindex4 - Vendor Reserve */

/**
* \brief Object/Entry names
*/
OBJCONST UCHAR OBJMEM aName0xF008[] = "Parameters Handing\000"
"Save Current Parameters\000"
"Restore Default Parameters\000"
"Checksum\000"
"Vendor Reserve\000\377";
#endif //#ifdef _OBJD_

#ifndef _SSC_DEVICE_OBJECTS_H_
/**
* \brief Object structure
*/
typedef struct OBJ_STRUCT_PACKED_START {
UINT16 u16SubIndex0;
UINT16 SaveCurrentParameters; /* Subindex1 - Save Current Parameters */
UINT16 RestoreDefaultParameters; /* Subindex2 - Restore Default Parameters */
UINT16 Checksum; /* Subindex3 - Checksum */
UINT16 VendorReserve; /* Subindex4 - Vendor Reserve */
} OBJ_STRUCT_PACKED_END
TOBJF008;
#endif //#ifndef _SSC_DEVICE_OBJECTS_H_

/**
* \brief Object variable
*/
PROTO TOBJF008 ParametersHanding0xF008
#if defined(_SSC_DEVICE_) && (_SSC_DEVICE_ == 1)
={4,0x0000,0x0000,0x0000,0x0000}
#endif
;
/** @}*/







#ifdef _OBJD_
TOBJECT    OBJMEM ApplicationObjDic[] = {
/* Object 0x1600 */
{NULL , NULL ,  0x1600 , {DEFTYPE_PDOMAPPING , 128 | (OBJCODE_REC << 8)} , asEntryDesc0x1600 , aName0x1600 , &DOUnit20x1600 , NULL , NULL , 0x0000 },
/* Object 0x1A00 */
{NULL , NULL ,  0x1A00 , {DEFTYPE_PDOMAPPING , 128 | (OBJCODE_REC << 8)} , asEntryDesc0x1A00 , aName0x1A00 , &DIUnit10x1A00 , NULL , NULL , 0x0000 },
/* Object 0x1C12 */
{NULL , NULL ,  0x1C12 , {DEFTYPE_UNSIGNED16 , 1 | (OBJCODE_ARR << 8)} , asEntryDesc0x1C12 , aName0x1C12 , &sRxPDOassign , NULL , NULL , 0x0000 },
/* Object 0x1C13 */
{NULL , NULL ,  0x1C13 , {DEFTYPE_UNSIGNED16 , 1 | (OBJCODE_ARR << 8)} , asEntryDesc0x1C13 , aName0x1C13 , &sTxPDOassign , NULL , NULL , 0x0000 },
/* Object 0x6000 */
{NULL , NULL ,  0x6000 , {DEFTYPE_UNSIGNED16 , 128 | (OBJCODE_ARR << 8)} , asEntryDesc0x6000 , aName0x6000 , &DIUnit10x6000 , NULL , NULL , 0x0000 },
/* Object 0x7000 */
{NULL , NULL ,  0x7000 , {DEFTYPE_UNSIGNED16 , 128 | (OBJCODE_ARR << 8)} , asEntryDesc0x7000 , aName0x7000 , &DOUnit20x7000 , NULL , NULL , 0x0000 },
/* Object 0xF008 */
{NULL , NULL ,  0xF008 , {DEFTYPE_RECORD , 4 | (OBJCODE_REC << 8)} , asEntryDesc0xF008 , aName0xF008 , &ParametersHanding0xF008 , NULL , NULL , 0x0000 },
{NULL,NULL, 0xFFFF, {0, 0}, NULL, NULL, NULL, NULL}};
#endif    //#ifdef _OBJD_

#undef PROTO

/** @}*/
#define _SSC_DEVICE_OBJECTS_H_
