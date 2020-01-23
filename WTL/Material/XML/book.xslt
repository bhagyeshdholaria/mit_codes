<?xml version="1.0"?>

<xsl:stylesheet version="1.0"
xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

<xsl:template match="/">
  <html>
  <body>
    <h2>Donors List</h2>
    <table border="1">
      <tr bgcolor="#9acd32">
        <th>Sr. No.</th>
        <th>Name</th>
		<th>Blood Group</th>
		<th>Pincodee</th>
		<th>Aadhar Number</th>
		<th>Contact Number</th>
      </tr>
      <xsl:for-each select="books/book">
        <tr>
          <td><xsl:value-of select="srno"/></td>
          <td><xsl:value-of select="name"/></td>
		  <td><xsl:value-of select="bloodg"/></td>
		  <td><xsl:value-of select="pincode"/></td>
          <td><xsl:value-of select="aadhar"/></td>
		  <td><xsl:value-of select="contact"/></td>
        </tr>
      </xsl:for-each>
    </table>
  </body>
  </html>
</xsl:template>

</xsl:stylesheet>