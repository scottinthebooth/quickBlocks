#pragma once
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
#include <vector>
#include "transaction.h"

// EXISTING_CODE
// EXISTING_CODE

//--------------------------------------------------------------------------
class QExecute : public CTransaction {
public:
    SFAddress _to;
    SFUintBN _value;
    string_q _data;

public:
    QExecute(void);
    QExecute(const QExecute& ex);
    virtual ~QExecute(void);
    QExecute& operator=(const QExecute& ex);

    DECLARE_NODE(QExecute);

    // EXISTING_CODE
    // EXISTING_CODE
    friend bool operator<(const QExecute& v1, const QExecute& v2);
    friend ostream& operator<<(ostream& os, const QExecute& item);

protected:
    void clear(void);
    void initialize(void);
    void duplicate(const QExecute& ex);
    bool readBackLevel(SFArchive& archive) override;

    // EXISTING_CODE
    // EXISTING_CODE
};

//--------------------------------------------------------------------------
inline QExecute::QExecute(void) {
    initialize();
    // EXISTING_CODE
    // EXISTING_CODE
}

//--------------------------------------------------------------------------
inline QExecute::QExecute(const QExecute& ex) {
    // EXISTING_CODE
    // EXISTING_CODE
    duplicate(ex);
}

// EXISTING_CODE
// EXISTING_CODE

//--------------------------------------------------------------------------
inline QExecute::~QExecute(void) {
    clear();
    // EXISTING_CODE
    // EXISTING_CODE
}

//--------------------------------------------------------------------------
inline void QExecute::clear(void) {
    // EXISTING_CODE
    // EXISTING_CODE
}

//--------------------------------------------------------------------------
inline void QExecute::initialize(void) {
    CTransaction::initialize();

    _to = "";
    _value = 0;
    _data = "";

    // EXISTING_CODE
    // EXISTING_CODE
}

//--------------------------------------------------------------------------
inline void QExecute::duplicate(const QExecute& ex) {
    clear();
    CTransaction::duplicate(ex);

    _to = ex._to;
    _value = ex._value;
    _data = ex._data;

    // EXISTING_CODE
    // EXISTING_CODE
    finishParse();
}

//--------------------------------------------------------------------------
inline QExecute& QExecute::operator=(const QExecute& ex) {
    duplicate(ex);
    // EXISTING_CODE
    // EXISTING_CODE
    return *this;
}

//-------------------------------------------------------------------------
inline bool operator<(const QExecute& v1, const QExecute& v2) {
    // EXISTING_CODE
    // EXISTING_CODE
    // No default sort defined in class definition, assume already sorted
    return true;
}

//---------------------------------------------------------------------------
typedef vector<QExecute> QExecuteArray;
extern SFArchive& operator>>(SFArchive& archive, QExecuteArray& array);
extern SFArchive& operator<<(SFArchive& archive, const QExecuteArray& array);

//---------------------------------------------------------------------------
// EXISTING_CODE
// EXISTING_CODE

