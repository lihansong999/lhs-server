package fwmysqlhelper

import (
	"database/sql"
)

// RowResult 一行查询结果
type RowResult map[string][]byte

// QueryResult 单语句查询结果
type QueryResult []RowResult

// MultiQueryResult 多语句查询结果
// 指针遍历样例:
// for statementsIndex, queryResult := range *multiQueryResult {
// 	fmt.Printf("%s%d%s\n", "第 ", statementsIndex+1, " 个语句查询结果 = {")
// 	if len(queryResult) == 0 {
// 		for rowIndex, rowResult := range queryResult {
// 			fmt.Printf("  %s%d%s\n", "第 ", rowIndex+1, " 行 = [")
// 			for name, value := range rowResult {
// 				fmt.Printf("    %s = %s\n", name, string(value))
// 			}
// 			fmt.Println("  ]")
// 		}
// 	} else {
// 		fmt.Println("  无结果")
// 	}
// 	fmt.Println("}")
// }
type MultiQueryResult []QueryResult

// MakeQueryResult 根据sql.Rows构造一个MultiQueryResult
// 调用前一定要先 defer rows.Close()
func MakeQueryResult(rows *sql.Rows) (*MultiQueryResult, error) {
	multiQueryResult := MultiQueryResult{}
	for haveNextResultSet := true; haveNextResultSet; haveNextResultSet = rows.NextResultSet() {
		queryResult := QueryResult{}
		for rows.Next() {
			columns, err := rows.Columns()
			if err != nil {
				return nil, err
			}
			values := make([]sql.RawBytes, len(columns))
			scanArgs := make([]interface{}, len(values))
			for i := range values {
				scanArgs[i] = &values[i]
			}
			err = rows.Scan(scanArgs...)
			if err != nil {
				return nil, err
			}
			rowResult := RowResult{}
			for i, col := range values {
				if col == nil {
					rowResult[columns[i]] = nil
				} else {
					s := make([]byte, len(col))
					copy(s, col)
					rowResult[columns[i]] = s
				}
			}
			queryResult = append(queryResult, rowResult)
		}
		if err := rows.Err(); err != nil {
			return nil, err
		}
		multiQueryResult = append(multiQueryResult, queryResult)
	}
	if err := rows.Err(); err != nil {
		return nil, err
	}
	return &multiQueryResult, nil
}

// GetSingleQueryResult 获得单语句查询结果
func GetSingleQueryResult(multiQueryResult *MultiQueryResult, index int) *QueryResult {
	if multiQueryResult == nil {
		return nil
	}
	if index >= len(*multiQueryResult) {
		return nil
	}
	return &((*multiQueryResult)[index])
}

// GetRowQueryResult 获得某行查询结果
func GetRowQueryResult(singleQueryResult *QueryResult, index int) *RowResult {
	if singleQueryResult == nil {
		return nil
	}
	if index >= len(*singleQueryResult) {
		return nil
	}
	return &((*singleQueryResult)[index])
}

// GetFirstRowQueryResult 得到第一个语句的第一行查询结果
func GetFirstRowQueryResult(multiQueryResult *MultiQueryResult) *RowResult {
	return GetRowQueryResult(GetSingleQueryResult(multiQueryResult, 0), 0)
}
