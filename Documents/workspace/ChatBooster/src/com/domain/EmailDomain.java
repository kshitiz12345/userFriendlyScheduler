package com.domain;

import java.util.ArrayList;
import java.util.List;

import javax.validation.constraints.NotNull;

import org.hibernate.validator.constraints.NotEmpty;

public class EmailDomain {

	private long number;
	private String emailId;
	private char delete;
	@NotEmpty
	private String emailText;
	@NotEmpty
	@NotNull
	private Long[] category;

	List<CategoryDomain> categoryDomainList = new ArrayList<CategoryDomain>();
	List<FeedDomain> feedDomainList = new ArrayList<FeedDomain>();

	public Long[] getCategory() {
		return category;
	}

	public void setCategory(Long[] category) {
		this.category = category;
	}

	public String getEmailText() {
		return emailText;
	}

	public void setEmailText(String emailText) {
		this.emailText = emailText;
	}

	public char getDelete() {
		return delete;
	}

	public void setDelete(char delete) {
		this.delete = delete;
	}

	public List<FeedDomain> getFeedDomainList() {
		return feedDomainList;
	}

	public void setFeedDomainList(List<FeedDomain> feedDomainList) {
		this.feedDomainList = feedDomainList;
	}

	public List<CategoryDomain> getCategoryDomainList() {
		return categoryDomainList;
	}

	public void setCategoryDomainList(List<CategoryDomain> categoryDomainList) {
		this.categoryDomainList = categoryDomainList;
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

}
