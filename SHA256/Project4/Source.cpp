//For CDatabase class
#include "odbcinst.h"
#include "afxdb.h"
//


CDatabase database;
CString SqlString;
CString strID, strName, strAge;
CString sDriver = L"ODBC Driver 11 for SQL Server";
CString sDsn;
int iRec = 0;

// Build ODBC connection string
sDsn.Format(L"ODBC;DRIVER={%s};DSN='';DBQ=%s;DATABASE=MYDBNAME", sDriver, NULL);
TRY{
	// Open the database
	database.Open(NULL,false,false,sDsn);

SqlString = "INSERT INTO MY_TABLE (id,name,age) VALUES (1,'Sanjaya',25)";
database.ExecuteSQL(SqlString);
// Close the database
database.Close();
}CATCH(CDBException, e) {
	// If a database exception occured, show error msg
	AfxMessageBox(L"Database error: " + e->m_strError);
}
END_CATCH;