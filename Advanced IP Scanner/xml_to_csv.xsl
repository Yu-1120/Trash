<?xml version="1.0" encoding="utf-8"?>
<!--
//////////////////////////////////////////////////////////////////////////////////////////
//
//  Разработано по служебному заданию ООО "Фаматек"
//  № ТД07-08 от 13 мая 2011 года
//
//  Автор: Петров Григорий Валерьевич
//  Модуль: xml_to_csv.xsl
// 
//////////////////////////////////////////////////////////////////////////////////////////
-->
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
<xsl:output method="text" encoding="utf-8" doctype-public="-//W3C//DTD XHTML 1.0 Strict//EN" doctype-system="http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd"/>
<xsl:template match="/">Status&#09;Name&#09;IP&#09;Radmin&#09;Http&#09;Https&#09;Ftp&#09;Shared folders&#09;NetBIOS name&#09;NetBIOS group&#09;Manufacturer&#09;MAC address&#09;User&#09;Comments
<xsl:for-each select="Advanced_IP_scanner/row">
	<xsl:if test="@status = 'alive'">Alive</xsl:if><xsl:if test="@status = 'dead'">Dead</xsl:if><xsl:if test="@status = 'unknown'">Unknown</xsl:if>&#09;<xsl:value-of select="@name"/>&#09;<xsl:value-of select="@ip"/>&#09;<xsl:if test="radmin"><xsl:for-each select="radmin"><xsl:value-of select="@port"/><xsl:if test="not(position()=last())">, </xsl:if></xsl:for-each></xsl:if>&#09;<xsl:if test="@has_http = 1"><xsl:choose><xsl:when test="@http_title"><xsl:value-of select="@http_title"/></xsl:when><xsl:otherwise>(no title)</xsl:otherwise></xsl:choose></xsl:if>&#09;<xsl:if test="@has_https = 1"><xsl:choose><xsl:when test="@https_title"><xsl:value-of select="@https_title"/></xsl:when><xsl:otherwise>(no title)</xsl:otherwise></xsl:choose></xsl:if>&#09;<xsl:if test="@has_ftp = 1"><xsl:choose><xsl:when test="@ftp_title"><xsl:value-of select="@ftp_title"/></xsl:when><xsl:otherwise>(no title)</xsl:otherwise></xsl:choose></xsl:if>&#09;<xsl:if test="share"><xsl:for-each select="share"><xsl:value-of select="@name"/><xsl:if test="not(position()=last())">, </xsl:if></xsl:for-each></xsl:if>&#09;<xsl:value-of select="@netbiosname"/>&#09;<xsl:value-of select="@netbiosgroup"/>&#09;<xsl:value-of select="@manufacturer"/>&#09;<xsl:value-of select="@mac"/>&#09;<xsl:value-of select="@user"/>&#09;<xsl:value-of select="@comments"/><xsl:text>&#10;</xsl:text>
</xsl:for-each>
</xsl:template>
</xsl:stylesheet>
