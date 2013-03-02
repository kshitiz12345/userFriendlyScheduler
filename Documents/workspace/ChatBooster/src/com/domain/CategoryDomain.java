package com.domain;

public class CategoryDomain {

	private long categoryId;
	private String category;

	@Override
	public int hashCode() {
		return new Long(categoryId).hashCode();
	}

	@Override
	public boolean equals(Object obj) {
		if (obj == null) {
			return false;
		}
		if (!(obj instanceof CategoryDomain)) {
			return false;
		}
		return this.categoryId == ((CategoryDomain) obj).getCategoryId();
	}

	public long getCategoryId() {
		return categoryId;
	}

	public void setCategoryId(long categoryId) {
		this.categoryId = categoryId;
	}

	public String getCategory() {
		return category;
	}

	public void setCategory(String category) {
		this.category = category;
	}

}
