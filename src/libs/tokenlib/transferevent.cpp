/*-------------------------------------------------------------------------------------------
 * QuickBlocks - Decentralized, useful, and detailed data from Ethereum blockchains
 * Copyright (c) 2018 Great Hill Corporation (http://quickblocks.io)
 *
 * This program is free software: you may redistribute it and/or modify it under the terms
 * of the GNU General Public License as published by the Free Software Foundation, either
 * version 3 of the License, or (at your option) any later version. This program is
 * distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even
 * the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details. You should have received a copy of the GNU General
 * Public License along with this program. If not, see http://www.gnu.org/licenses/.
 *-------------------------------------------------------------------------------------------*/
/*
 * This file was generated with makeClass. Edit only those parts of the code inside
 * of 'EXISTING_CODE' tags.
 */
#include "transferevent.h"
#include "etherlib.h"

//---------------------------------------------------------------------------
IMPLEMENT_NODE(QTransferEvent, CLogEntry);

//---------------------------------------------------------------------------
static string_q nextTransfereventChunk(const string_q& fieldIn, const void *dataPtr);
static string_q nextTransfereventChunk_custom(const string_q& fieldIn, const void *dataPtr);

//---------------------------------------------------------------------------
void QTransferEvent::Format(CExportContext& ctx, const string_q& fmtIn, void *dataPtr) const {
    if (!m_showing)
        return;

    if (fmtIn.empty()) {
        ctx << toJson();
        return;
    }

    string_q fmt = fmtIn;
    // EXISTING_CODE
    // EXISTING_CODE

    while (!fmt.empty())
        ctx << getNextChunk(fmt, nextTransfereventChunk, this);
}

//---------------------------------------------------------------------------
string_q nextTransfereventChunk(const string_q& fieldIn, const void *dataPtr) {
    if (dataPtr)
        return ((const QTransferEvent *)dataPtr)->getValueByName(fieldIn);

    // EXISTING_CODE
    // EXISTING_CODE

    return fldNotFound(fieldIn);
}

//---------------------------------------------------------------------------------------------------
bool QTransferEvent::setValueByName(const string_q& fieldName, const string_q& fieldValue) {
    // EXISTING_CODE
    // EXISTING_CODE

    if (CLogEntry::setValueByName(fieldName, fieldValue))
        return true;

    switch (tolower(fieldName[0])) {
        case '_':
            if ( fieldName % "_from" ) { _from = toAddress(fieldValue); return true; }
            if ( fieldName % "_to" ) { _to = toAddress(fieldValue); return true; }
            if ( fieldName % "_value" ) { _value = toWei(fieldValue); return true; }
            break;
        default:
            break;
    }
    return false;
}

//---------------------------------------------------------------------------------------------------
void QTransferEvent::finishParse() {
    // EXISTING_CODE
    // EXISTING_CODE
}

//---------------------------------------------------------------------------------------------------
bool QTransferEvent::Serialize(SFArchive& archive) {

    if (archive.isWriting())
        return ((const QTransferEvent*)this)->SerializeC(archive);

    // If we're reading a back level, read the whole thing and we're done.
    if (readBackLevel(archive))
        return true;

    // EXISTING_CODE
    // EXISTING_CODE
    archive >> _from;
    archive >> _to;
    archive >> _value;
    finishParse();
    return true;
}

//---------------------------------------------------------------------------------------------------
bool QTransferEvent::SerializeC(SFArchive& archive) const {

    // Writing always write the latest version of the data
    CLogEntry::SerializeC(archive);

    // EXISTING_CODE
    // EXISTING_CODE
    archive << _from;
    archive << _to;
    archive << _value;

    return true;
}

//---------------------------------------------------------------------------
SFArchive& operator>>(SFArchive& archive, QTransferEventArray& array) {
    uint64_t count;
    archive >> count;
    array.resize(count);
    for (size_t i = 0 ; i < count ; i++) {
        ASSERT(i < array.capacity());
        array.at(i).Serialize(archive);
    }
    return archive;
}

//---------------------------------------------------------------------------
SFArchive& operator<<(SFArchive& archive, const QTransferEventArray& array) {
    uint64_t count = array.size();
    archive << count;
    for (size_t i = 0 ; i < array.size() ; i++)
        array[i].SerializeC(archive);
    return archive;
}

//---------------------------------------------------------------------------
void QTransferEvent::registerClass(void) {
    static bool been_here = false;
    if (been_here) return;
    been_here = true;

    CLogEntry::registerClass();

    size_t fieldNum = 1000;
    ADD_FIELD(QTransferEvent, "schema",  T_NUMBER, ++fieldNum);
    ADD_FIELD(QTransferEvent, "deleted", T_BOOL,  ++fieldNum);
    ADD_FIELD(QTransferEvent, "showing", T_BOOL,  ++fieldNum);
    ADD_FIELD(QTransferEvent, "_from", T_ADDRESS, ++fieldNum);
    ADD_FIELD(QTransferEvent, "_to", T_ADDRESS, ++fieldNum);
    ADD_FIELD(QTransferEvent, "_value", T_NUMBER, ++fieldNum);

    // Hide our internal fields, user can turn them on if they like
    HIDE_FIELD(QTransferEvent, "schema");
    HIDE_FIELD(QTransferEvent, "deleted");
    HIDE_FIELD(QTransferEvent, "showing");

    // EXISTING_CODE
    // EXISTING_CODE
}

//---------------------------------------------------------------------------
string_q nextTransfereventChunk_custom(const string_q& fieldIn, const void *dataPtr) {
    const QTransferEvent *tra = (const QTransferEvent *)dataPtr;
    if (tra) {
        switch (tolower(fieldIn[0])) {
            // EXISTING_CODE
            // EXISTING_CODE
            case 'p':
                // Display only the fields of this node, not it's parent type
                if ( fieldIn % "parsed" )
                    return nextBasenodeChunk(fieldIn, tra);
                // EXISTING_CODE
                // EXISTING_CODE
                break;

            default:
                break;
        }
    }

    return "";
}

//---------------------------------------------------------------------------
bool QTransferEvent::readBackLevel(SFArchive& archive) {

    CLogEntry::readBackLevel(archive);
    bool done = false;
    // EXISTING_CODE
    // EXISTING_CODE
    return done;
}

//---------------------------------------------------------------------------
string_q QTransferEvent::getValueByName(const string_q& fieldName) const {

    // Give customized code a chance to override first
    string_q ret = nextTransfereventChunk_custom(fieldName, this);
    if (!ret.empty())
        return ret;

    // Return field values
    switch (tolower(fieldName[0])) {
        case '_':
            if ( fieldName % "_from" ) return fromAddress(_from);
            if ( fieldName % "_to" ) return fromAddress(_to);
            if ( fieldName % "_value" ) return asStringBN(_value);
            break;
    }

    // EXISTING_CODE
    // EXISTING_CODE

    // Finally, give the parent class a chance
    return CLogEntry::getValueByName(fieldName);
}

//-------------------------------------------------------------------------
ostream& operator<<(ostream& os, const QTransferEvent& item) {
    // EXISTING_CODE
    // EXISTING_CODE

    os << item.Format() << "\n";
    return os;
}

//---------------------------------------------------------------------------
// EXISTING_CODE
// EXISTING_CODE

