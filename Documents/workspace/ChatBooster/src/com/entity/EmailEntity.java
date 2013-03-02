package com.entity;

import java.util.ArrayList;
import java.util.List;

import javax.persistence.CascadeType;
import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.Id;
import javax.persistence.JoinColumn;
import javax.persistence.JoinTable;
import javax.persistence.ManyToMany;

@Entity(name = "email")
public class EmailEntity {

	@Id
	@GeneratedValue
	private long number;
	private String emailId;
	private char deleted;
	
	@ManyToMany(cascade = { CascadeType.REFRESH })
	@JoinTable(name = "EMAIL_CATEGORY", joinColumns = { @JoinColumn(name = "EMAILID") }, inverseJoinColumns = { @JoinColumn(name = "CATEGORYID") })
	private List<CategoryEntity> categoryEntityList = new ArrayList<CategoryEntity>();

	public char getDeleted() {
		return deleted;
	}

	public void setDeleted(char deleted) {
		this.deleted = deleted;
	}

	public long getNumber() {
		return number;
	}

	public void setNumber(long number) {
		this.number = number;
	}

	public String getEmailId() {
		return emailId;
	}

	public void setEmailId(String emailId) {
		this.emailId = emailId;
	}

	public List<CategoryEntity> getCategoryEntityList() {
		return categoryEntityList;
	}

	public void setCategoryEntityList(List<CategoryEntity> categoryEntityList) {
		this.categoryEntityList = categoryEntityList;
	}

}
