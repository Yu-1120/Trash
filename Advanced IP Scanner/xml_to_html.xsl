<?xml version="1.0" encoding="utf-8"?>
<!--
//////////////////////////////////////////////////////////////////////////////////////////
//
//  Разработано по служебному заданию ООО "Фаматек"
//  № ТД07-08 от 13 мая 2011 года
//
//  Автор: Петров Григорий Валерьевич
//  Модуль: xml_to_html.xsl
// 
//////////////////////////////////////////////////////////////////////////////////////////
-->
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
<xsl:output method="html" encoding="utf-8" doctype-public="-//W3C//DTD XHTML 1.0 Strict//EN" doctype-system="http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd"/>
<xsl:template match="/">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
<title>Favorites list</title>
<style type="text/css">
@media screen
{
  body {font-family:Verdana, Geneva, sans-serif; background:#fff; color:#10494E;}
  table {border:1px solid #b3cddc;!important border-collapse:collapse; border-spacing:0px;}
  th {background-color:#c8dfec; text-align:left; padding:5px 10px;}
  td {padding-left:10px; padding-right:10px;}
  .r1 {background-color:#e9f4fb;}
  .r2 {background-color:#f3f8fb;}
  .head {padding-top:3px; padding-bottom:3px; border-top:1px solid #fff;}
  .res, .rhead {font-size:0.75em; padding-top:1px; padding-bottom:2px;}
  .res {margin-left:100px; padding-left:5px;}
  .rhead {float:left; text-align:right; width:100px;}
}
</style>
</head>
<body>
<table cellpadding="0" width="100%">
  <tr>
    <th>Status</th>
    <th>Name</th>
    <th>IP</th>
    <th>NetBIOS name</th>
    <th>NetBIOS group</th>
    <th>Manufacturer</th>
    <th>MAC address</th>
    <th>User</th>
    <th>Comments</th>
  </tr>
  <xsl:for-each select="Advanced_IP_scanner/row">
  <tr class="r1">
    <td class="head"><xsl:if test="@status = 'alive'">Alive</xsl:if>
        <xsl:if test="@status = 'dead'">Dead</xsl:if>
        <xsl:if test="@status = 'unknown'">Unknown</xsl:if></td>
    <td class="head"><xsl:value-of select="@name"/></td>
    <td class="head"><xsl:value-of select="@ip"/></td>
    <td class="head"><xsl:value-of select="@netbiosname"/></td>
    <td class="head"><xsl:value-of select="@netbiosgroup"/></td>
    <td class="head"><xsl:value-of select="@manufacturer"/></td>
    <td class="head"><xsl:value-of select="@mac"/></td>
    <td class="head"><xsl:value-of select="@user"/></td>
    <td class="head"><xsl:value-of select="@comments"/></td>
  </tr>
  <xsl:if test="@has_http = 1">
  <tr class="r2">
  	<td></td>
    <td colspan="7">
    <div class="rhead">Http:</div>
    <div class="res"><xsl:choose><xsl:when test="@http_title"><xsl:value-of select="@http_title"/></xsl:when><xsl:otherwise>(no title)</xsl:otherwise></xsl:choose> </div>
    </td>
  </tr>
  </xsl:if>
  <xsl:if test="@has_https = 1">
  <tr class="r2">
  	<td></td>
    <td colspan="7">
    <div class="rhead">Https:</div>
    <div class="res"><xsl:choose><xsl:when test="@https_title"><xsl:value-of select="@https_title"/></xsl:when><xsl:otherwise>(no title)</xsl:otherwise></xsl:choose> </div>
    </td>
  </tr>
  </xsl:if>
  <xsl:if test="@has_ftp = 1">
  <tr class="r2">
  	<td></td>
    <td colspan="7">
    <div class="rhead">Ftp:</div>
    <div class="res"><xsl:choose><xsl:when test="@ftp_title"><xsl:value-of select="@ftp_title"/></xsl:when><xsl:otherwise>(no title)</xsl:otherwise></xsl:choose> </div>
    </td>
  </tr>
  </xsl:if>
  <xsl:if test="share">
  <tr class="r2">
  	<td></td>
    <td colspan="7">
    <div class="rhead">Shared folder:</div>
    	<xsl:for-each select="share">
        	<div class="res"><xsl:value-of select="@name"/></div>
        </xsl:for-each> 
    </td>
  </tr>
  </xsl:if>
  <xsl:if test="radmin">
  <tr class="r2">
  	<td></td>
    <td colspan="7">
    <div class="rhead">Radmin ports:</div>
    	<xsl:for-each select="radmin">
        	<div class="res"><xsl:value-of select="@port"/></div>
        </xsl:for-each> 
    </td>
  </tr>
  </xsl:if>
  </xsl:for-each>
</table>
</body>
</html>
</xsl:template>
</xsl:stylesheet>
