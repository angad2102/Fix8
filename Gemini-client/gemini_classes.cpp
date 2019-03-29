//-------------------------------------------------------------------------------------------------
// *** f8c generated file: DO NOT EDIT! Created: 2019-03-27 15:15:55 ***
//-------------------------------------------------------------------------------------------------
/*

Fix8 is released under the GNU LESSER GENERAL PUBLIC LICENSE Version 3.

Fix8 Open Source FIX Engine.
Copyright (C) 2010-19 David L. Dight <fix@fix8.org>

Fix8 is free software: you can  redistribute it and / or modify  it under the  terms of the
GNU Lesser General  Public License as  published  by the Free  Software Foundation,  either
version 3 of the License, or (at your option) any later version.

Fix8 is distributed in the hope  that it will be useful, but WITHOUT ANY WARRANTY;  without
even the  implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

You should  have received a copy of the GNU Lesser General Public  License along with Fix8.
If not, see <http://www.gnu.org/licenses/>.

*******************************************************************************************
*                Special note for Fix8 compiler generated source code                     *
*                                                                                         *
* Binary works  that are the results of compilation of code that is generated by the Fix8 *
* compiler  can be released  without releasing your  source code as  long as your  binary *
* links dynamically  against an  unmodified version of the Fix8 library.  You are however *
* required to leave the copyright text in the generated code.                             *
*                                                                                         *
*******************************************************************************************

BECAUSE THE PROGRAM IS  LICENSED FREE OF  CHARGE, THERE IS NO  WARRANTY FOR THE PROGRAM, TO
THE EXTENT  PERMITTED  BY  APPLICABLE  LAW.  EXCEPT WHEN  OTHERWISE  STATED IN  WRITING THE
COPYRIGHT HOLDERS AND/OR OTHER PARTIES  PROVIDE THE PROGRAM "AS IS" WITHOUT WARRANTY OF ANY
KIND,  EITHER EXPRESSED   OR   IMPLIED,  INCLUDING,  BUT   NOT  LIMITED   TO,  THE  IMPLIED
WARRANTIES  OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  THE ENTIRE RISK AS TO
THE QUALITY AND PERFORMANCE OF THE PROGRAM IS WITH YOU. SHOULD THE PROGRAM PROVE DEFECTIVE,
YOU ASSUME THE COST OF ALL NECESSARY SERVICING, REPAIR OR CORRECTION.

IN NO EVENT UNLESS REQUIRED  BY APPLICABLE LAW  OR AGREED TO IN  WRITING WILL ANY COPYRIGHT
HOLDER, OR  ANY OTHER PARTY  WHO MAY MODIFY  AND/OR REDISTRIBUTE  THE PROGRAM AS  PERMITTED
ABOVE,  BE  LIABLE  TO  YOU  FOR  DAMAGES,  INCLUDING  ANY  GENERAL, SPECIAL, INCIDENTAL OR
CONSEQUENTIAL DAMAGES ARISING OUT OF THE USE OR INABILITY TO USE THE PROGRAM (INCLUDING BUT
NOT LIMITED TO LOSS OF DATA OR DATA BEING RENDERED INACCURATE OR LOSSES SUSTAINED BY YOU OR
THIRD PARTIES OR A FAILURE OF THE PROGRAM TO OPERATE WITH ANY OTHER PROGRAMS), EVEN IF SUCH
HOLDER OR OTHER PARTY HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.

*/

//-------------------------------------------------------------------------------------------------
#include <fix8/f8config.h>
#if defined FIX8_MAGIC_NUM && FIX8_MAGIC_NUM > 16793600L
#error gemini_classes.cpp version 1.4.0 is out of date. Please regenerate with f8c.
#endif
//-------------------------------------------------------------------------------------------------
// gemini_classes.cpp
//-------------------------------------------------------------------------------------------------
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <vector>
#include <map>
#include <list>
#include <set>
#include <iterator>
#include <algorithm>
#include <cerrno>
#include <string.h>
// f8 includes
#include <fix8/f8exception.hpp>
#include <fix8/hypersleep.hpp>
#include <fix8/mpmc.hpp>
#include <fix8/thread.hpp>
#include <fix8/f8types.hpp>
#include <fix8/f8utils.hpp>
#include <fix8/tickval.hpp>
#include <fix8/logger.hpp>
#include <fix8/traits.hpp>
#include <fix8/field.hpp>
#include <fix8/message.hpp>
#include "gemini_types.hpp"
#include "gemini_router.hpp"
#include "gemini_classes.hpp"
//-------------------------------------------------------------------------------------------------
namespace FIX8 {
namespace GEMINI {

namespace {

//-------------------------------------------------------------------------------------------------

const char *cn[] // Component names
{
   "",
   "CommissionData", // 1
   "DiscretionInstructions", // 2
   "FinancingDetails", // 3
   "Instrument", // 4
   "InstrumentExtension", // 5
   "InstrumentLeg", // 6
   "LegBenchmarkCurveData", // 7
   "LegStipulations", // 8
   "NestedParties", // 9
   "NestedParties2", // 10
   "NestedParties3", // 11
   "OrderQtyData", // 12
   "Parties", // 13
   "PegInstructions", // 14
   "PositionAmountData", // 15
   "PositionQty", // 16
   "SettlInstructionsData", // 17
   "SettlParties", // 18
   "SpreadOrBenchmarkCurveData", // 19
   "Stipulations", // 20
   "TrdRegTimestamps", // 21
   "UnderlyingInstrument", // 22
   "UnderlyingStipulations", // 23
   "YieldData", // 24
};

} // namespace

//-------------------------------------------------------------------------------------------------
const GEMINI::gemini_BaseMsgEntry::Pair msgpairs[] 
{
   { "0", { Type2Type<GEMINI::Heartbeat>(), "Heartbeat" } },
   { "1", { Type2Type<GEMINI::TestRequest>(), "TestRequest" } },
   { "2", { Type2Type<GEMINI::ResendRequest>(), "ResendRequest" } },
   { "3", { Type2Type<GEMINI::Reject>(), "Reject" } },
   { "4", { Type2Type<GEMINI::SequenceReset>(), "SequenceReset" } },
   { "5", { Type2Type<GEMINI::Logout>(), "Logout" } },
   { "6", { Type2Type<GEMINI::IndicationOfInterest>(), "IndicationOfInterest" } },
   { "7", { Type2Type<GEMINI::Advertisement>(), "Advertisement" } },
   { "8", { Type2Type<GEMINI::ExecutionReport>(), "ExecutionReport" } },
   { "9", { Type2Type<GEMINI::OrderCancelReject>(), "OrderCancelReject" } },
   { "A", { Type2Type<GEMINI::Logon>(), "Logon" } },
   { "AA", { Type2Type<GEMINI::DerivativeSecurityList>(), "DerivativeSecurityList" } },
   { "AB", { Type2Type<GEMINI::NewOrderMultileg>(), "NewOrderMultileg" } },
   { "AC", { Type2Type<GEMINI::MultilegOrderCancelReplaceRequest>(), "MultilegOrderCancelReplaceRequest" } },
   { "AD", { Type2Type<GEMINI::TradeCaptureReportRequest>(), "TradeCaptureReportRequest" } },
   { "AE", { Type2Type<GEMINI::TradeCaptureReport>(), "TradeCaptureReport" } },
   { "AF", { Type2Type<GEMINI::OrderMassStatusRequest>(), "OrderMassStatusRequest" } },
   { "AG", { Type2Type<GEMINI::QuoteRequestReject>(), "QuoteRequestReject" } },
   { "AH", { Type2Type<GEMINI::RFQRequest>(), "RFQRequest" } },
   { "AI", { Type2Type<GEMINI::QuoteStatusReport>(), "QuoteStatusReport" } },
   { "AJ", { Type2Type<GEMINI::QuoteResponse>(), "QuoteResponse" } },
   { "AK", { Type2Type<GEMINI::Confirmation>(), "Confirmation" } },
   { "AL", { Type2Type<GEMINI::PositionMaintenanceRequest>(), "PositionMaintenanceRequest" } },
   { "AM", { Type2Type<GEMINI::PositionMaintenanceReport>(), "PositionMaintenanceReport" } },
   { "AN", { Type2Type<GEMINI::RequestForPositions>(), "RequestForPositions" } },
   { "AO", { Type2Type<GEMINI::RequestForPositionsAck>(), "RequestForPositionsAck" } },
   { "AP", { Type2Type<GEMINI::PositionReport>(), "PositionReport" } },
   { "AQ", { Type2Type<GEMINI::TradeCaptureReportRequestAck>(), "TradeCaptureReportRequestAck" } },
   { "AR", { Type2Type<GEMINI::TradeCaptureReportAck>(), "TradeCaptureReportAck" } },
   { "AS", { Type2Type<GEMINI::AllocationReport>(), "AllocationReport" } },
   { "AT", { Type2Type<GEMINI::AllocationReportAck>(), "AllocationReportAck" } },
   { "AU", { Type2Type<GEMINI::ConfirmationAck>(), "ConfirmationAck" } },
   { "AV", { Type2Type<GEMINI::SettlementInstructionRequest>(), "SettlementInstructionRequest" } },
   { "AW", { Type2Type<GEMINI::AssignmentReport>(), "AssignmentReport" } },
   { "AX", { Type2Type<GEMINI::CollateralRequest>(), "CollateralRequest" } },
   { "AY", { Type2Type<GEMINI::CollateralAssignment>(), "CollateralAssignment" } },
   { "AZ", { Type2Type<GEMINI::CollateralResponse>(), "CollateralResponse" } },
   { "B", { Type2Type<GEMINI::News>(), "News" } },
   { "BA", { Type2Type<GEMINI::CollateralReport>(), "CollateralReport" } },
   { "BB", { Type2Type<GEMINI::CollateralInquiry>(), "CollateralInquiry" } },
   { "BC", { Type2Type<GEMINI::NetworkStatusRequest>(), "NetworkStatusRequest" } },
   { "BD", { Type2Type<GEMINI::NetworkStatusResponse>(), "NetworkStatusResponse" } },
   { "BE", { Type2Type<GEMINI::UserRequest>(), "UserRequest" } },
   { "BF", { Type2Type<GEMINI::UserResponse>(), "UserResponse" } },
   { "BG", { Type2Type<GEMINI::CollateralInquiryAck>(), "CollateralInquiryAck" } },
   { "BH", { Type2Type<GEMINI::ConfirmationRequest>(), "ConfirmationRequest" } },
   { "C", { Type2Type<GEMINI::Email>(), "Email" } },
   { "D", { Type2Type<GEMINI::NewOrderSingle>(), "NewOrderSingle" } },
   { "E", { Type2Type<GEMINI::NewOrderList>(), "NewOrderList" } },
   { "F", { Type2Type<GEMINI::OrderCancelRequest>(), "OrderCancelRequest" } },
   { "G", { Type2Type<GEMINI::OrderCancelReplaceRequest>(), "OrderCancelReplaceRequest" } },
   { "H", { Type2Type<GEMINI::OrderStatusRequest>(), "OrderStatusRequest" } },
   { "J", { Type2Type<GEMINI::AllocationInstruction>(), "AllocationInstruction" } },
   { "K", { Type2Type<GEMINI::ListCancelRequest>(), "ListCancelRequest" } },
   { "L", { Type2Type<GEMINI::ListExecute>(), "ListExecute" } },
   { "M", { Type2Type<GEMINI::ListStatusRequest>(), "ListStatusRequest" } },
   { "N", { Type2Type<GEMINI::ListStatus>(), "ListStatus" } },
   { "P", { Type2Type<GEMINI::AllocationInstructionAck>(), "AllocationInstructionAck" } },
   { "Q", { Type2Type<GEMINI::DontKnowTrade>(), "DontKnowTrade" } },
   { "R", { Type2Type<GEMINI::QuoteRequest>(), "QuoteRequest" } },
   { "S", { Type2Type<GEMINI::Quote>(), "Quote" } },
   { "T", { Type2Type<GEMINI::SettlementInstructions>(), "SettlementInstructions" } },
   { "V", { Type2Type<GEMINI::MarketDataRequest>(), "MarketDataRequest" } },
   { "W", { Type2Type<GEMINI::MarketDataSnapshotFullRefresh>(), "MarketDataSnapshotFullRefresh" } },
   { "X", { Type2Type<GEMINI::MarketDataIncrementalRefresh>(), "MarketDataIncrementalRefresh" } },
   { "Y", { Type2Type<GEMINI::MarketDataRequestReject>(), "MarketDataRequestReject" } },
   { "Z", { Type2Type<GEMINI::QuoteCancel>(), "QuoteCancel" } },
   { "a", { Type2Type<GEMINI::QuoteStatusRequest>(), "QuoteStatusRequest" } },
   { "b", { Type2Type<GEMINI::MassQuoteAcknowledgement>(), "MassQuoteAcknowledgement" } },
   { "c", { Type2Type<GEMINI::SecurityDefinitionRequest>(), "SecurityDefinitionRequest" } },
   { "d", { Type2Type<GEMINI::SecurityDefinition>(), "SecurityDefinition" } },
   { "e", { Type2Type<GEMINI::SecurityStatusRequest>(), "SecurityStatusRequest" } },
   { "f", { Type2Type<GEMINI::SecurityStatus>(), "SecurityStatus" } },
   { "g", { Type2Type<GEMINI::TradingSessionStatusRequest>(), "TradingSessionStatusRequest" } },
   { "h", { Type2Type<GEMINI::TradingSessionStatus>(), "TradingSessionStatus" } },
   { "header", { Type2Type<GEMINI::header, bool>(), "header" } },
   { "i", { Type2Type<GEMINI::MassQuote>(), "MassQuote" } },
   { "j", { Type2Type<GEMINI::BusinessMessageReject>(), "BusinessMessageReject" } },
   { "k", { Type2Type<GEMINI::BidRequest>(), "BidRequest" } },
   { "l", { Type2Type<GEMINI::BidResponse>(), "BidResponse" } },
   { "m", { Type2Type<GEMINI::ListStrikePrice>(), "ListStrikePrice" } },
   { "o", { Type2Type<GEMINI::RegistrationInstructions>(), "RegistrationInstructions" } },
   { "p", { Type2Type<GEMINI::RegistrationInstructionsResponse>(), "RegistrationInstructionsResponse" } },
   { "q", { Type2Type<GEMINI::OrderMassCancelRequest>(), "OrderMassCancelRequest" } },
   { "r", { Type2Type<GEMINI::OrderMassCancelReport>(), "OrderMassCancelReport" } },
   { "s", { Type2Type<GEMINI::NewOrderCross>(), "NewOrderCross" } },
   { "t", { Type2Type<GEMINI::CrossOrderCancelReplaceRequest>(), "CrossOrderCancelReplaceRequest" } },
   { "trailer", { Type2Type<GEMINI::trailer, bool>(), "trailer" } },
   { "u", { Type2Type<GEMINI::CrossOrderCancelRequest>(), "CrossOrderCancelRequest" } },
   { "v", { Type2Type<GEMINI::SecurityTypeRequest>(), "SecurityTypeRequest" } },
   { "w", { Type2Type<GEMINI::SecurityTypes>(), "SecurityTypes" } },
   { "x", { Type2Type<GEMINI::SecurityListRequest>(), "SecurityListRequest" } },
   { "y", { Type2Type<GEMINI::SecurityList>(), "SecurityList" } },
   { "z", { Type2Type<GEMINI::DerivativeSecurityListRequest>(), "DerivativeSecurityListRequest" } }
}; // 94

extern const gemini_BaseEntry::Pair fldpairs[];

/// Compiler generated metadata object, accessed through this function.
const F8MetaCntx& ctx() // avoid SIOF
{
   static const gemini_BaseMsgEntry bme(msgpairs, 94);
   static const gemini_BaseEntry be(fldpairs, 915);
   static const F8MetaCntx _ctx(4400, bme, be, cn, "FIX.4.4");
   return _ctx;
}

} // namespace GEMINI

// Compiler generated metadata object accessible outside namespace through this function.
extern "C"
{
   const F8MetaCntx& GEMINI_ctx() { return GEMINI::ctx(); }
}

} // namespace FIX8
