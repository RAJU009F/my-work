import java.io.*;
import java.util.*;
import java.sql.*;
import java.lang.*;

// JDBC program to connect oracle.jdbc.driver.OracleDriver

class JDBCTest{
	
	public static void main(String args[])
	{
		try{
			
			// register driver class

			Class.forName("oracle.jdbc.driver.OracleDriver");
			
			// create the connection object
			
			Connection con =  DriverManager.getConnection("jdbc:oracle:thin:@localhost:1521:xe", "hr", "hr");
			
			// create statement
			Statement stmt =  con.createStatement();
			
			// execute query
			
			ResultSet rs = stmt.executeQuery("select * from Employees");
			while(rs.next())
				System.out.println(rs.getInt(1));
			con.close();
			
		}catch(Exception e){
			
			System.out.println(e);
		}
		
	}
	
	
}